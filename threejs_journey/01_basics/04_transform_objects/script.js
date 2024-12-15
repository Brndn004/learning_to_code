import * as THREE from 'three';

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
mesh.position.set(1.7, -0.6, 1);
mesh.scale.set(1.5, 0.25, 0.5);
mesh.rotation.set(Math.PI / 2, Math.PI / 4, 0);

// Add object to scene.
scene.add(mesh);

// Camera.
const camera = new THREE.PerspectiveCamera(75, sizes.width / sizes.height);
camera.position.set(1, 1.5, 3);
camera.lookAt(0, 0, 0);  // lookAt is available for any Object3D.
// It is optional to add the camera to the scene, but "will prevent bugs later".
scene.add(camera);

// More logs.
console.log("Mesh length is:", mesh.position.length());  // `position` is a `Vector3` object.
console.log("Distance to camera is:", mesh.position.distanceTo(camera.position));
console.log("Normalized mesh position is:", mesh.position.normalize());

// Axes helper.
const axesHelper = new THREE.AxesHelper(2);  // 2 units long.
scene.add(axesHelper);

// Group of objects.
const group = new THREE.Group();
group.scale.y = 2;
group.rotation.y = 0.2;
scene.add(group);

const cube1 = new THREE.Mesh(
  new THREE.BoxGeometry(1, 1, 1),
  new THREE.MeshBasicMaterial({ color: 0xff0000 })
);
cube1.position.x = -1.5;
group.add(cube1);

const cube2 = new THREE.Mesh(
  new THREE.BoxGeometry(1, 1, 1),
  new THREE.MeshBasicMaterial({ color: 0x00ff00 })
);
cube2.position.x = 0;
group.add(cube2);

const cube3 = new THREE.Mesh(
  new THREE.BoxGeometry(1, 1, 1),
  new THREE.MeshBasicMaterial({ color: 0x0000ff })
);
cube3.position.x = 1.5;
group.add(cube3);

// Renderer -- keep this last.
const renderer = new THREE.WebGLRenderer({
    canvas: canvas
});
renderer.setSize(sizes.width, sizes.height);
renderer.render(scene, camera);
