* Build tool: takes your source and turns it into an actual website.
  * E.g. Vite, Webpack, Parcel, etc.
* Bundle: a single file that contains all your code.
  * Bundles are created by build tools.
* Environment map: an image of what's surrounding the scene.
  * Use it to add reflection, refraction, and lighting in addition to any actual
    lights that you define.
* GLSL: a C-like language for writing shaders.
  * Stands for "(Open)GL Shading Language".
* GSAP: GreenSock Animation Platform.
  * A JavaScript library for animating HTML elements.
* Minify: remove unnecessary characters from your code.
* Mipmapping: creating half a smaller version of a texture again and again until
  you get a 1x1 texture.
  * This is used for things like viewing a texture from far away or at an angle.
* Moire pattern: a generally negative effect occuring when aliasing changes what
  is rendered.
  * Also used for practical purposes sometimes, like a passive navigation system
    that points boats / planes in the right direction. Look it up!
* npm: Node Package Manager.
  * Used to install packages for Node.js, similar to pip for Python.
* OpenGL: Open Graphics Library.
* Texture: an image that is applied to an object, wrapped onto it, typically.
* Texture, albedo: the most simple texture; take the pixels and apply them to
  the geometry.
* Texture, alpha: a grayscale image that determines the transparency of the
  object.
* Texture, ambient occlusion: creates fake shadows.
* Texture, height: a grayscale image that moves the vertices to create some
  relief.
  * You must add subdivisions to the geometry to see the effect.
* Texture, matcap: material capture, a technique that uses pre-rendered images
  to simulate lighting.
* Texture, metalness: specify which part is metalic to help create reflections.
* Texture, normal: a texture that determines the direction of the normals.
  * It doesn't move vertices, but it will trick the light into thinking the face
    is oriented differently.
  * Does not require subdivisions.
* Texture, PBR: Physically Based Rendering.
  * A set of textures that work together to create realistic materials.
  * Groups many techniques to create realistic materials.
* Texture, roughness: dissipates light.
* UV unwrapping: Putting a flat texture onto a non-flat geometry.
  * Here UV is referring to a 2D coordinate system where `u` and `v` are the
    axes. This is a standard coordinate system for images.
* Z-fighting: two faces seem to fight for which one will be rendered above the
  other.
