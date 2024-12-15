* Mipmaps are only needed for the `minFilter` property.
  * If you are using `THREE.NearestFilter`, you should deactivate mipmaps, e.g. with `texture.generateMipmaps = false`.
* Textures must be sized as a power of 2 or ThreeJS will stretch them and produce a warning in the console.
