var opsys = process.platform;
var device_path='';

const { autoDetect } = require('@serialport/bindings-cpp');
const Binding = autoDetect();
console.log(opsys);
Binding.list().then(ports => {
    //console.log(ports);
    if (opsys == "win32" || opsys == "win64") {
        const port = ports.find(port => /2341/i.test(port.vendorId));
        if (port) device_path=port.path;
    } else if (opsys == "linux") {
        const port = ports.find(port => /8086/i.test(port.vendorId));
        if (port) device_path=port.path;
    }
    //const port = ports.find(port => /8086/i.test(port.vendorId));
    console.log(device_path);
});