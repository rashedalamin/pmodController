const express = require("express");
const http = require("http");
const { Server } = require("socket.io");
const { autoDetect } = require('@serialport/bindings-cpp');
const { SerialPort, ReadlineParser } = require('serialport');


const app = express();
const server = http.createServer(app);
const io = new Server(server);

var device_path='/dev/ttyArduino';

const port = new SerialPort({
    path: device_path,
    baudRate: 9600,
    dataBits: 8,
    parity: 'none',
    stopBits: 1,
    flowControl: false,
});
const parser = port.pipe(new ReadlineParser());
app.get("/", (req, res)=>{
    res.sendFile('/public/index.html' , { root: '.' });
});

io.on('connection', (socket) => {
    socket.on('toArduino', function (data) {
        console.log(data);
        port.write( data.pin );
    });
});


parser.on('data', function(data){
    console.log("received from arduino "+data);
    io.emit('data',data);
});


server.listen(3000,()=>{
    console.log("listening on *.3000");
});
console.log("Web Server Started go to `http://localhost:3000` in your  Browser.");