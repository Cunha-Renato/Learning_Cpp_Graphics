# Learning_Cpp_Graphics
Learning win32 and C++ graphics. I managed to create a graphics library for windows, its not very useful or eficient and i didn't comment at all, this version is the first one and the worst one. I plan to keep updating it but less often.

# How to use

The sistem is based on a Window object, a Scene Manager and Scenes that the user will create.

First create a Window variable, the a SceneManager variable and assign the window to it. Then is up to the user to create new Scenes that derive from the Scene abstract class.

For now i doubt that anyone will be able to use it because somethings are hidden and hard to understand (especially without comments). I'll be making the game PONG using this library and upload on github.
  
# Requirements

Compile using the MSVC and use the (user32.lib) and (d2d1.lib).
