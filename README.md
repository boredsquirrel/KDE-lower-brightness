# KDE-lower-brightness

A Kwin effect to reduce the brightness of the screen lower than supported by the display. Makes most sense on OLED or at least IPS displays.

Warning: I have no idea what I am doing, this is experimental.

## Build on OpenSUSE tumbleweed
I am using a distrobox to compile the effect

```
# build reqs
sudo zypper in kf6-coreaddons-devel kf6-kguiaddons-devel kf6-kconfigwidgets-devel kwin6-devel qt6-core-devel extra-cmake-modules cmake clang

# target directories
mkdir -p ~/.local/share/kwin/effects/LowerBrightness/
mkdir -p ~/.local/lib/qt6/plugins/kwin/effects/

# cmake
export CMAKE_PREFIX_PATH=/usr/lib64/cmake/KF6:$CMAKE_PREFIX_PATH

mkdir -p ./build
cmake -B build -DCMAKE_INSTALL_PREFIX=~/.local
cmake --build build --parallel

# install
cmake --install build
```

apply

```
kwin_wayland --replace &
```

test

```
qdbus org.kde.KWin /KWin org.kde.KWin.supportedEffects | grep lowerbrightness
```
