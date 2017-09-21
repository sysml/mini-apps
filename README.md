Mini-Apps
=========

Mini-Apps contains a set of applications used for testing Mini-OS features.

Before building any of the applications, you will need:
* [Mini-OS source tree](https://github.com/sysml/mini-os)
* [Mini-OS toolchain](https://github.com/sysml/toolchain) for building Newlib and Lwip libraries
* [Xen source tree](https://github.com/sysml/xen) for the Xen public interfaces

To build an application, first go to its subdirectory and run ``make`` with the environment variables set for the prerequisites:  
```
$ cd idle
$ make XEN_ROOT=... MINIOS_ROOT=... NEWLIB_ROOT=... LWIP_ROOT=... <Mini-OS specific flags>
```

The build process will create the images in the ``build`` subdirectory of the application:
```
$ ls build
idle    idle_x86_64     idle_x86_64_nostrip  idle_x86_64.o     mini-os
idle.o  idle_x86_64.gz  idle_x86_64_.o       idle_x86_64.syms
```
