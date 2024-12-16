* MeshBasicMaterial: the most basic material.
  * MeshBasicMaterial.map: apply a texture on the surface of the geometry.
  * MeshBasicMaterial.color: apply a uniform color to the surface. When changing
    .color, you must instantiate a THREE.Color class.
* MeshNormalMaterial: shows the normal vectors of the geometry.
* MeshMatcapMaterial: shows fake lighting based on material capture.
  * The lighting is the same regardless of orientation.
* MeshDepthMaterial: color the geometry based on closeness to the camera's near
  and far clipping planes.
* MeshLambertMaterial: requires light, as it reacts to it.
  * Supports the same properties as MeshBasicMaterial, plus some related to
    lighting.
  * The most performant material that reacts to light.
* MeshPhongMaterial: similar to lambert, but better results at the cost of worse
  performance.
* MeshToonMaterial: cartoonish.
  * You likely need to change the minFilter / magFilter to see good results,
    depending on your gradientTexture.
* MeshStandardMaterial: for physically-based-rendering (PBR).
* MeshPhysicalMaterial: a more advanced version of MeshStandardMaterial (in fact
  it is a subclass).
  * Adds properties like clearcoat, clearcoatRoughness, reflectivity, etc.
  * The worst in terms of performance.
* PointsMaterial: handle particles, their size, color, what's drawn in them,
  etc.
* ShaderMaterial / RawShaderMaterial: used to create your own materials with
  GLSL (OpenGL Shading Language).

