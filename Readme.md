# Machine informations

Displays common informations about host machine.

May be used as a library or as a command.

## Usage

`$> machineInfo (--serv) (--port $1)`

- --serv if present, start a server
- --port default 4040

### Modules

- CpuModule
- RamModule
- NetModule

Example:
```C++
CpuModule cpu;

std::cout << cpu.getCpuName() << std::endl;
```
Example output:

`Intel(R) Core(TM) i7-7500U CPU @ 2.70GHz`

