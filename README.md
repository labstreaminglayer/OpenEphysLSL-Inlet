# Introduction

This is an [Open Ephys GUI](https://github.com/open-ephys/plugin-GUI) data thread plugin for [LSL](https://labstreaminglayer.readthedocs.io/index.html) streams.
Please read the guide regarding compiling plugins from [open-ephys](https://open-ephys.github.io/gui-docs/Developer-Guide/Compiling-plugins.html) and install cmake.

## How to build

The plugin repo needs to be cloned inside a directory (e.g. MyPlugins) that is at the same level as [plugin-GUI](https://github.com/open-ephys/plugin-GUI/), for example:

```
/Users/foo/plugin-GUI
/Users/foo/plugin-GUI/MyPlugins/lsl-inlet
```

### macOS

A debug version of the plugin will not work with a release version of `Open Ephys GUI` and a release version of the plugin will not work with a debug version of `Open Ephys GUI`. Keep this in mind when deciding how to generate the makefiles.

Download liblsl:

```
mkdir liblsl
cd liblsl
curl -OL https://github.com/sccn/liblsl/releases/download/v1.16.0/liblsl-1.16.0-OSX_amd64.tar.bz2
tar xvf liblsl-1.16.0-OSX_amd64.tar.bz2
```

On macOS either "Xcode" or "Unix Makefiles" can be generated and used to successfully build the plugin.
If you prefer to work with VSCode then "Unix Makefiles" should be used.
Generate the Makefile using:

```
cd Build
cmake -DCMAKE_OSX_ARCHITECTURES="x86_64" -G "Unix Makefiles" ..
```

For a release build run:

```
cd Build
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_OSX_ARCHITECTURES="x86_64" -G "Unix Makefiles" ..
```

Build a binary:

```
cd Build
make
```

Install the plugin:

```
cd Build
make install
```

This will copy the plugin (`OpenEphysLSL-Inlet.bundle`) to the `$HOME/Application Support/open-ephys/plugins-api8/` folder
and will available the next time `Open Ephys GUI` is launched.

### Windows

The build was tested using Visual Studio 2022 Community Edition.
First, download liblsl from [GitHub](https://github.com/sccn/liblsl/releases/download/v1.16.0/liblsl-1.16.0-Win_amd64.zip) and extract it inside the plugin directory.
The folder structure can be:

```
OpenEphysLSL-Inlet
|
|--liblsl
	|
	|-- bin
	|-- include
	|-- lib
```

Open `Developer Command Prompt for VS 2022` and generate the Makefile using cmake:

```
cd Build
cmake -G "Visual Studio 17 2022" -A x64 ..
```

You can now open the `ALL_BUILD.vcxproj` file from the Build folder with Visual Studio and build a binary. 

To install the plugin copy the file `OpenEphysLSL-Inlet.dll` to the `C:\ProgramData\Open Ephys\plugins-api8` folder and copy
the file `lsl.dll` to the `C:\ProgramData\Open Ephys\shared-api8` folder.

The plugin will load the next time `Open Ephys GUI` is launched.