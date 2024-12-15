import * as THREE from 'three'
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls.js'
// The path for the image is relative to the static/ directory, which is found
// automatically by Vite, the build tool we are using.
import imageSource from '/textures/door/color.jpg'
import curiousBrandon from '/textures/curious_brandon.png'

import * as DebugUi from './debug_ui.js'

/**
 * Debug UI.
 */
const gui = DebugUi.createGui(
  DebugUi.createGuiConfig({
    title: 'Lesson 10: Textures',
    closeFolders: true,
  }),
);
DebugUi.listenKeystrokes(gui);

/**
 * Base
 */
// Canvas
const canvas = document.querySelector('canvas.webgl')

// Scene
const scene = new THREE.Scene()

/**
 * Textures.
 */

const image = new Image();
// // Pure JS.
// const texture = new THREE.Texture(image);
// texture.colorSpace = THREE.SRGBColorSpace;
// image.addEventListener('load', () => {
//   texture.needsUpdate = true;
// });
// image.src = imageSource;
// image.src = curiousBrandon;
// texture.colorSpace = THREE.SRGBColorSpace;

// // Or use a TextureLoader for convenience and additional features.
// const textureLoader = new THREE.TextureLoader();
// const texture = textureLoader.load(
//   imageSource,  // The image itself.
//   () => { console.log('loading finished') }, // Finished callback.
//   () => { console.log('loading progressing') },  // Progressing callback.
//   () => { console.log('loading error') },  // Error callback.
// );
// texture.colorSpace = THREE.SRGBColorSpace;

// Or use a LoadingManager for more control and many images.
const loadingManager = new THREE.LoadingManager()
loadingManager.onStart = () => { console.log('Loading started') };
loadingManager.onLoad = () => { console.log('Loading finished') };
loadingManager.onProgress = () => { console.log('Loading progressing') };
loadingManager.onError = () => { console.log('Loading error') };
// Then load the textures of interest.
const textureLoader = new THREE.TextureLoader(loadingManager);
const colorTexture = textureLoader.load('/textures/minecraft.png');
// const colorTexture = textureLoader.load('/textures/checkerboard-1024x1024.png');
// const colorTexture = textureLoader.load('/textures/door/color.jpg');
colorTexture.colorSpace = THREE.SRGBColorSpace;
colorTexture.generateMipmaps = false;
colorTexture.minFilter = THREE.NearestFilter;
colorTexture.magFilter = THREE.NearestFilter;
const alphaTexture = textureLoader.load('/textures/door/alpha.jpg');
const heightTexture = textureLoader.load('/textures/door/height.jpg');
const normalTexture = textureLoader.load('/textures/door/normal.jpg');
const ambientOcclusionTexture = textureLoader.load(
  '/textures/door/ambientOcclusion.jpg');
const metalnessTexture = textureLoader.load('/textures/door/metalness.jpg');
const roughnessTexture = textureLoader.load('/textures/door/roughness.jpg');

/**
 * Object
 */
const geometry = new THREE.BoxGeometry(1, 1, 1)
const material = new THREE.MeshBasicMaterial({ map: colorTexture });
const mesh = new THREE.Mesh(geometry, material)
scene.add(mesh)
DebugUi.debugMesh(
  gui,
  mesh,
  DebugUi.createMeshConfig({
    meshName: 'BoxMesh',
  }),
);

/**
 * Sizes
 */
const sizes = {
    width: window.innerWidth,
    height: window.innerHeight
}

window.addEventListener('resize', () =>
{
    // Update sizes
    sizes.width = window.innerWidth
    sizes.height = window.innerHeight

    // Update camera
    camera.aspect = sizes.width / sizes.height
    camera.updateProjectionMatrix()

    // Update renderer
    renderer.setSize(sizes.width, sizes.height)
    renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2))
})

/**
 * Camera
 */
// Base camera
const camera = new THREE.PerspectiveCamera(75, sizes.width / sizes.height, 0.1, 100)
camera.position.x = 1
camera.position.y = 1
camera.position.z = 1
scene.add(camera)

// Controls
const controls = new OrbitControls(camera, canvas)
controls.enableDamping = true

/**
 * Renderer
 */
const renderer = new THREE.WebGLRenderer({
    canvas: canvas
})
renderer.setSize(sizes.width, sizes.height)
renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2))

/**
 * Animate
 */
const clock = new THREE.Clock()

const tick = () =>
{
    const elapsedTime = clock.getElapsedTime()

    // Update controls
    controls.update()

    // Render
    renderer.render(scene, camera)

    // Call tick again on the next frame
    window.requestAnimationFrame(tick)
}

tick()
