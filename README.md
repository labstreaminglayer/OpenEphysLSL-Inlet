# LabStreamingLayer OpenEphys Data Thread Plugin

This repository contains a [LabStreamingLayer](http://labstreaminglayer.readthedocs.io/) **Data Thread** plugin for the [Open Ephys GUI](https://github.com/open-ephys/plugin-GUI).

## Releases

TODO: These don't exist yet...

Check the repository's [releases](https://github.com/labstreaminglayer/OpenEphysLSL-Inlet/releases) page for a downloadable plugin.

## Building

### Prerequisite: liblsl

You will need `liblsl` on your local disk in a location that CMake can find. This is platform-dependent.

#### MacOS

The easiest way is to use homebrew:

`brew install labstreaminglayer/tap/lsl`

Otherwise, see the [Miscellaneous Platforms](#miscellaneous-platforms) section.

#### Windows

Download `liblsl-x.xx.x-Win_amd64.zip` (where x.xx.x is the latest version number) from the [liblsl Releases page](https://github.com/sccn/liblsl/releases).
Extract that archive somewhere convenient.
Pass the path to the extracted folder as a CMake argument (`-DLSL_INSTALL_ROOT=path/to/extracted/liblsl`).

#### Ubuntu Linux

Download `liblsl-x.xx.x-yyy_amd64.deb` (where x.xx.x is the latest version number and yyy is the name of your Ubuntu distribution) from the [liblsl Releases page](https://github.com/sccn/liblsl/releases). Use your Ubuntu package manager to install it.

#### Miscellaneous Platforms

See the [liblsl README](https://github.com/sccn/liblsl#building-liblsl) for more options.

### Prerequisite: OpenEphys Plugin-GUI

You also need the OpenEphys Plugin GUI Source code.

Download or clone from its repo [here](https://github.com/open-ephys/plugin-GUI).

Your folder structure should look like the following

```
shared_root/
    - plugin-GUI
    - OEPlugins/
        OpenEphysLSL-Inlet (this repo)
```

### Repository structure

This repository contains 3 top-level directories:

- `Build` - Plugin build files will be auto-generated here. These files will be ignored in all `git` commits.
- `Source` - All plugin source files (`.h` and `.cpp`) should live here. There can be as many source code sub-directories as needed.
- `Resources` - This is where you should store any non-source-code files, such as library files or scripts.

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
