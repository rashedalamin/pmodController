const express = require("express");
const http = require("http");
const { Server } = require("socket.io");
const { autoDetect } = require('@serialport/bindings-cpp');
const { SerialPort, ReadlineParser } = require('serialport');


const app = express();
const server = http.createServer(app);
const io = new Server(server);

var device_path='/dev/ttyArduino';

//custom path
//const { autoDetect } = require('@serialport/bindings-cpp');
const Binding = autoDetect();
console.log(opsys);
Binding.list().then(ports => {
    //console.log(ports);
    if (opsys == "win32" || opsys == "win64") {
        const port = ports.find(port => /2341/i.test(port.vendorId));
        if (port) device_path=port.path;
    } 
    // else if (opsys == "linux") {
    //     const port = ports.find(port => /8086/i.test(port.vendorId));
    //     if (port) device_path=port.path;
    // }
    //const port = ports.find(port => /8086/i.test(port.vendorId));
    console.log(device_path);
});





var opsys = process.platform;

if (opsys == "win32" || opsys == "win64") {
    device_path="COM4";
} else if (opsys == "linux") {
    device_path='/dev/ttyArduino';
}
console.log(device_path);
// Binding.list().then(ports => {
//     if (opsys == "win32" || opsys == "win64") {
//         const port = ports.find(port => /2341/i.test(port.vendorId));
//         if (port) device_path=port.path;
//     } else if (opsys == "linux") {
//         const port = ports.find(port => /8086/i.test(port.vendorId));
//         if (port) device_path=port.path;
//     }
//     // const port = ports.find(port => /8086/i.test(port.vendorId));
//     //console.log(device_path);
// });

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
        port.write( data.command );
    });
});


parser.on('data', function(data){
    console.log("received from arduino "+data);
    io.emit('data',JSON.parse(data));
});


server.listen(3000,()=>{
    console.log("listening on *.3000");
});
console.log("Web Server Started go to `http://localhost:3000` in your  Browser.");