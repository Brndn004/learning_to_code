import './style.css';
import * as THREE from 'three';
import gsap from 'gsap';

// Hello, world!
console.log("JavaScript is working");
console.log(THREE);

// Constants.
const sizes = {
    width: 800,  // Pixels.
    height: 600  // Pixels.
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
const camera = new THREE.PerspectiveCamera(75, sizes.width / sizes.height);
camera.position.z = 3;
// It is optional to add the camera to the scene, but "will prevent bugs later".
scene.add(camera);

// Renderer.
const renderer = new THREE.WebGLRenderer({
    canvas: canvas
});
renderer.setSize(sizes.width, sizes.height);

// // Time.
// const clock = new THREE.Clock();

// Has a built-in requestAnimationFrame, but we still need to render
// the scene ourselves in the `tick` function.
gsap.to(mesh.position, { duration: 1, delay: 1, x: 2 });

// Start animation.
const tick = () => {
  // // Seconds since the clock was created.
  // const secondsSinceClockCreation = clock.getElapsedTime();

  // mesh.position.x = Math.sin(secondsSinceClockCreation);
  // mesh.position.y = Math.sin(secondsSinceClockCreation);
  // mesh.rotation.y = secondsSinceClockCreation;

  // camera.position.x = Math.sin(secondsSinceClockCreation);
  // camera.position.y = Math.sin(secondsSinceClockCreation);
  // camera.lookAt(mesh.position);

  renderer.render(scene, camera);
  window.requestAnimationFrame(tick);
}
tick();
