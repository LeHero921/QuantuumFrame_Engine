
Rendering is split into 2 parts:
1) The engines Renderer, which provides all rendering functionality
2) and a rendering pipeline, which works with the rendering backend and combines functions to render the scene.

This approach makes the rendering process more flexible and allows for changing the pipeline on the fly.
All objects in a scene  that contain rendering information gets send, when appropriate, to the renderer (pipeline) which should construct a rendering list.

Example:

A NES style pipeline:

The pipeline has flags, which objects can have, to sort the process.
It also handles z-sorting etc.
- background flag
- z sort
- z depth
- positioning
- animations
- 