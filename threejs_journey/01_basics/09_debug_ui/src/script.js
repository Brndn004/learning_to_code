import './style.css'
import * as THREE from 'three'
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls.js'
import gsap from 'gsap'
import GUI from 'lil-gui'

/**
 * Base
 */
// Canvas
const canvas = document.querySelector('canvas.webgl')

// Scene
const scene = new THREE.Scene()

/**
 * Object
 */
const geometry = new THREE.BoxGeometry(
  1,  // Width.
  1,  // Height.
  1,  // Depth.
  2,  // Width segments.
  2,  // Height segments.
  2,  // Depth segments.
)
const material = new THREE.MeshBasicMaterial({ color: '#00a7ff' , wireframe: true })
const mesh = new THREE.Mesh(geometry, material)
scene.add(mesh)

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
camera.position.z = 2
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
 * Debug.
 */
const gui = new GUI();
gui.add(
  mesh.position,  // Object to modify via GUI.
  'y',  // Property of the object to be modified.
  -3,  // Min value.
  3,  // Max value.
  0.01,  // Step size.
);
gui.add(mesh.position, 'x').min(-3).max(3).step(0.01).name('boxPositionX');
gui.add(mesh, 'visible');
gui.add(material, 'wireframe');
gui.addColor(material, 'color')
  .onChange((value) => {
    console.log(value.getHexString());
  });

const debugObject = {
  subdivision: 2,
};
debugObject.spin = () => {
  gsap.to(mesh.rotation, { duration: 1, y: mesh.rotation.y + Math.PI * 2 });
}
gui.add(debugObject, 'spin');
gui
  .add(debugObject, 'subdivision')
  .min(1)
  .max(20)
  .step(1)
  .name('boxSubdivisions')
  .onFinishChange(() => {
    mesh.geometry.dispose();
    mesh.geometry = new THREE.BoxGeometry(
      1,  // Width.
      1,  // Height.
      1,  // Depth.
      debugObject.subdivision,  // Width segments.
      debugObject.subdivision,  // Height segments.
      debugObject.subdivision,  // Depth segments.
    );
  });
const myNamJeff = gui.addFolder('myNamJeff');
myNamJeff.add(mesh.position, 'z').min(-3).max(3).step(0.01).name('boxPositionZ');
myNamJeff.close();
// gui.hide();

window.addEventListener('keydown', (event) => {
  if (event.key == 'h') {
    gui.show(gui._hidden);
  }
});

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
