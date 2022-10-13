# Data Thread Plugin Template

This repository contains a template for building **Data Thread** plugins for the [Open Ephys GUI](https://github.com/open-ephys/plugin-GUI). Data Thread plugins typically communicate with an external piece of hardware with an acquisition clock that is not synchronized with the GUI's signal processing callbacks. Examples of commonly used Data Thread plugins include [Neuropixels PXI](https://github.com/open-ephys-plugins/neuropixels-pxi) and the [Rhythm Plugins](https://github.com/open-ephys-plugins/rhythm-plugins).

Information on the Open Ephys Plugin API can be found on [the GUI's documentation site](https://open-ephys.github.io/gui-docs/Developer-Guide/Open-Ephys-Plugin-API.html).

## Creating a new Data Thread Plugin

1. Click "Use this template" to instantiate a new repository under your GitHub account. 
2. Clone the new repository into a directory at the same level as the `plugin-GUI` repository. This is typically named `OEPlugins`, but it can have any name you'd like.
3. Modify the [OpenEphysLib.cpp file](https://open-ephys.github.io/gui-docs/Developer-Guide/Creating-a-new-plugin.html) to include your plugin's name and version number.
4. Create the plugin [build files](https://open-ephys.github.io/gui-docs/Developer-Guide/Compiling-plugins.html) using CMake.
5. Use Visual Studio (Windows), Xcode (macOS), or `make` (Linux) to compile the plugin.
6. Edit the code to add custom functionality, and add additional source files as needed.

## Repository structure

This repository contains 3 top-level directories:

- `Build` - Plugin build files will be auto-generated here. These files will be ignored in all `git` commits.
- `Source` - All plugin source files (`.h` and `.cpp`) should live here. There can be as many source code sub-directories as needed.
- `Resources` - This is where you should store any non-source-code files, such as library files or scripts.

## Using external libraries

To link the plugin to external libraries, it is necessary to manually edit the Build/CMakeLists.txt file. The code for linking libraries is located in comments at the end.
For most common libraries, the `find_package` option is recommended. An example would be

```cmake
find_package(ZLIB)
target_link_libraries(${PLUGIN_NAME} ${ZLIB_LIBRARIES})
target_include_directories(${PLUGIN_NAME} PRIVATE ${ZLIB_INCLUDE_DIRS})
```

If there is no standard package finder for cmake, `find_library`and `find_path` can be used to find the library and include files respectively. The commands will search in a variety of standard locations For example

```cmake
find_library(ZMQ_LIBRARIES NAMES libzmq-v120-mt-4_0_4 zmq zmq-v120-mt-4_0_4) #the different names after names are not a list of libraries to include, but a list of possible names the library might have, useful for multiple architectures. find_library will return the first library found that matches any of the names
find_path(ZMQ_INCLUDE_DIRS zmq.h)

target_link_libraries(${PLUGIN_NAME} ${ZMQ_LIBRARIES})
target_include_directories(${PLUGIN_NAME} PRIVATE ${ZMQ_INCLUDE_DIRS})
```

### Providing libraries for Windows

Since Windows does not have standardized paths for libraries, as Linux and macOS do, it is sometimes useful to pack the appropriate Windows version of the required libraries alongside the plugin.
To do so, a _libs_ directory has to be created **at the top level** of the repository, alongside this README file, and files from all required libraries placed there. The required folder structure is:

```
    libs
    ├─ include           #library headers
    ├─ lib
        ├─ x64           #64-bit compile-time (.lib) files
        └─ x86           #32-bit compile time (.lib) files, if needed
    └─ bin
        ├─ x64           #64-bit runtime (.dll) files
        └─ x86           #32-bit runtime (.dll) files, if needed
```

DLLs in the bin directories will be copied to the open-ephys GUI _shared_ folder when installing.
