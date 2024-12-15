import './style.css';
import * as THREE from 'three';
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls.js';

// Hello, world!
console.log("JavaScript is working");
console.log(THREE);

// Constants.
const sizes = {
    width: window.innerWidth,  // Pixels.
    height: window.innerHeight  // Pixels.
};

// Canvas.
const canvas = document.querySelector('canvas.webgl');

// Scene.
const scene = new THREE.Scene();

// Object.
const geometry = new THREE.BoxGeometry(1, 1, 1);
const material = new THREE.MeshBasicMaterial({ color: 0xff0000 });
const mesh = new THREE.Mesh(geometry, material);

// Add object to scene.
scene.add(mesh);

// Camera.
const camera = new THREE.PerspectiveCamera(
  75,  // Field of view.
  sizes.width / sizes.height,  // Aspect ratio.
  1,  // Near clipping plane.
  50,  // Far clipping plane.
);
// const aspectRatio = sizes.width / sizes.height;
// const camera = new THREE.OrthographicCamera(
//   -1 * aspectRatio,  // Left.
//   1 * aspectRatio,  // Right.
//   1,  // Top.
//   -1,  // Bottom.
//   0.1,  // Near clipping plane.
//   50,  // Far clipping plane.
// );
camera.position.z = 3;
camera.lookAt(mesh.position);
// It is optional to add the camera to the scene, but "will prevent bugs later".
scene.add(camera);

// Renderer.
const renderer = new THREE.WebGLRenderer({
    canvas: canvas
});
renderer.setSize(sizes.width, sizes.height);

// Cursor.
const cursor = {
  x: 0,
  y: 0
};
const normalizationMagnitude = 0.5;
window.addEventListener('mousemove', (event) => {
  cursor.x = event.clientX / sizes.width - normalizationMagnitude;
  // Note: clientY increases going downward, which is reversed from the Three.js
  // convention.
  cursor.y = -(event.clientY / sizes.height - normalizationMagnitude);
  // console.log(cursor.x, cursor.y);
});

console.log(window.devicePixelRatio);

// Resize.
window.addEventListener('resize', () => {
  // Update sizes.
  sizes.width = window.innerWidth;
  sizes.height = window.innerHeight;

  // Update camera.
  camera.aspect = sizes.width / sizes.height;
  camera.updateProjectionMatrix();

  // Update renderer.
  renderer.setSize(sizes.width, sizes.height);
});

// Fullscreen.
window.addEventListener('dblclick', () => {
  if (!document.fullscreenElement) {
    canvas.requestFullscreen();
  } else {
    document.exitFullscreen();
  }
});

// Controls.
const controls = new OrbitControls(camera, canvas);
// // Not very useful for this lesson, but this just sets the default location
// // of the controls, i.e. the point of rotation for the camera when you first
// // load the page.
// controls.target.y = 2;
// controls.update();
controls.enableDamping = true;

// Start animation.
const tick = () => {
  // camera.position.x = Math.sin(cursor.x * Math.PI * 2) * 2;
  // camera.position.z = Math.cos(cursor.x * Math.PI * 2) * 2;
  // camera.position.y = cursor.y * 3;
  // camera.lookAt(mesh.position);

  controls.update();
  renderer.render(scene, camera);
  window.requestAnimationFrame(tick);
}
tick();
