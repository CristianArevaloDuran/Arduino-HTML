import { SerialPort } from "serialport";
import express from "express";
import path from 'path';
import { fileURLToPath } from 'url';
import { WebSocketServer } from "ws";

const app = express();

app.use(express.json());


const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);

app.get("/", (req, res) => {
    res.sendFile(__dirname + "/html/index.html");
});

const wss = new WebSocketServer({ port: 8080 });

const arduino = new SerialPort({
    path: 'COM3',
    baudRate: 9600,
});

wss.on("connection", (ws) => {
    console.log("Client connected");
});

arduino.on('data', (data) => {
    wss.clients.forEach((client) => {
        if (client.readyState === client.OPEN) {
            client.send(data.toString());
        }
    });
});

app.listen(3000, () => {
    console.log("Server running");
});