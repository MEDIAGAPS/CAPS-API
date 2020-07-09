## Overview
The ARIB to SRT is a simple demo that can read a MPEG TS file with ARIB subtitles and extract and convert the Arib sbutiltle to an SRT file.

## Building

### Using command line

```
inside root ./AribToSRT
mkdir build
cd build
cmake -G "Visual Studio 15 2017" -A x64 ../
```

### Using the graphical version of CMake:

```
Open CMake GUI.
Under Where to build the binaries, same path as source plus build.
Click Configure and select Visual Studio 15 2017 Win64, then press Generate.
```

### Build solution
```
Inside the build folder, open the AribToSRT.sln and build the solution
After that, inside the bin folder (AribToSRT\build\bin) you may find the AribToSRT.exe to test the demo.
Copy the AribToSRT.exe and place it inside AribToSrt\bin folder
```

## Demo Usage
After copying the AribToSrt.exe to AribToSrt\bin folder you should have the executable next to all the other .dll file.

AribToSRT usage
```
Invalid program usage. Use program as:

AribToSRT.exe <input_video> <output_dir>
```

Example:
```
AribToSRT.exe ..\samples\TS1globo.ts ..\samples\
```

You may download the samples files used to tests this demo in the following website - https://tsduck.io/streams/?name=brazil-isdb-tb 

```
Starting demo.
--> API log: Creating file handle to: C:\work\Caps\demos\AribToSRT\samples\TS1globo.ts
--> API log: 0.00% loaded
--> API log: ARIB Closed Captions at pid : 534
--> API log: ARIB Closed Captions at pid : 278
--> API log: 1.43% loaded
--> API log: 2.62% loaded
--> API log: 3.89% loaded
--> API log: 5.30% loaded
--> API log: 6.63% loaded
--> API log: Creating file handle to: C:\work\Caps\demos\AribToSRT\samples/subtitle_id_278.srt
--> API log: Creating file handle to: C:\work\Caps\demos\AribToSRT\samples/subtitle_id_534.srt
```

## License
Arib To SRT is distributed under the terms of the Apache License Version 2. See the accompanying license file for details. The license enables usage of Arib To SRT in both commercial and non-commercial applications, without restrictions on the licensing applied to the combined work.

## Contacts
Looking for a different solutions or help in your development, get in contact with us - info@mediagaps.com. 

We would love to hear your story and know if we can help you fill the gap.

