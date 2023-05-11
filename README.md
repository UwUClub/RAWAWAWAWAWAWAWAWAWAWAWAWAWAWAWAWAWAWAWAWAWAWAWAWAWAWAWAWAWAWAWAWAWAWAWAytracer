# Raytracer

Raytracer is a little application that can simulate raytracing on geometrical elements.

## Contents

- [Requirements](#requirements)
- [Communication](#communication)
- [Installation](#installation)
- [Compilation](#compilation)
- [Usage](#usage)
- [Credits](#credits)
- [License](#license)

## Requirements

- g++ 20+

## Communication

- If you have a bug or an issue, please contact us.


## Installation

### SSH

> G++ 20+, LibConfig and SFML are required to build Raytracer.

```bash
git clone git@github.com:UwUClub/RAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAytracer.git raytracer
```

### HTTPS

Use any tools that can clone by HTTPS, use https://github.com/UwUClub/RAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAWAytracer.git

## Compilation

### Using the script

```bash
./build.sh
```
or

```bash
bash build.sh
```

**If you have some errors but the compilation works, please ignore them.**

## Usage
./raytracer <config_file>

### Quick Start

```bash
./raytracer tests/test.json
```

### Plugins
A list of plugin are implemented, those are dynamic libraries.
You can theorically add your own plugins to the project.
Just drop the .so in the *plugins* folder
And implement our **Api.hpp**, to let our library handler load it.

### Config file example

```markdown
camera :
{
  resolution = { width = 1920; height = 1080; };
  position = { x = 0; y = -100; z = 20; };
  rotation = { x = 0; y = 0; z = 0; };
  fieldOfView = 72.0; # In degree
};

primitives :
{
  # List of spheres
  Sphere = (
    { x = 60; y = 5; z = 40; r = 25; color = { r = 255; g = 64; b = 64; }; } ,
    { x = -40; y = 20; z = -10; r = 35; color = { r = 64; g = 255; b = 64; }; }
  ) ;
  # List of planes
  Planes = (
    { axis = "Z" ; position = -20; color = { r = 64; g = 64; b = 255; }; }
  ) ;
};

lights :
{
  ambient = 0.4; # Multiplier of ambient light
  diffuse = 0.6; # Multiplier of diffuse light

  # List of point lights
  PointLight = (
    { x = 400; y = 100; z = 500; }
  ) ;
};

```

- **camera** : Indicate that we are creating a new camera
    - **resolution** : Two int representing the resolution of the camera
    - **position** : The position of the camera in a 3D world
    - **rotation** : The rotation (orientation) of the camera in a 3D world
- **primitives** : Indicate that we will create *primitives*
    - **THE FIELD HERE DEPENDS OF WHAT YOU HAVE IMPLEMENTED**
- **lights** : Indicate that we will create the lights
    - **ambient** : The multiplier of ambient light
    - **diffuse** : The multiplier of diffuse light
    - **PointLight** or **DirectionalLight** : Indicate the type of light we will create
        - **x** : The x pos of the camera in a 3D world
        - **y** : The y pos of the camera in a 3D world
        - **z** : The z pos of the camera in a 3D world

## Credits

- Valentin Gegoux
- Baptiste Laran
- Mathéo Martin
- Maxence Labourel

## License

Raytracer is developped by the UwUClub for Epitech.
