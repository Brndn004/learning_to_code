import * as THREE from 'three'
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls.js'
import { RGBELoader } from 'three/examples/jsm/loaders/RGBELoader.js'

import * as DebugUi from './debug_ui.js'

/**
 * Debug UI.
 */
const gui = DebugUi.createGui(
  DebugUi.createGuiConfig({
    title: 'Lesson 11: Materials',
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
 * Textures.
 */
const textureLoader = new THREE.TextureLoader();

const doorColorTexture = textureLoader.load('/textures/door/color.jpg');
const doorAlphaTexture = textureLoader.load('/textures/door/alpha.jpg');
const doorAmbientOcclusionTexture = textureLoader.load(
  '/textures/door/ambientOcclusion.jpg');
const doorHeightTexture = textureLoader.load('/textures/door/height.jpg');
const doorNormalTexture = textureLoader.load('/textures/door/normal.jpg');
const doorMetalnessTexture = textureLoader.load('/textures/door/metalness.jpg');
const doorRoughnessTexture = textureLoader.load('/textures/door/roughness.jpg');
// const matcapTexture = textureLoader.load('/textures/matcaps/1.png');
// const matcapTexture = textureLoader.load('/textures/matcaps/2.png');
const matcapTexture = textureLoader.load('/textures/matcaps/3.png');
// const matcapTexture = textureLoader.load('/textures/matcaps/4.png');
// const matcapTexture = textureLoader.load('/textures/matcaps/5.png');
// const matcapTexture = textureLoader.load('/textures/matcaps/6.png');
// const matcapTexture = textureLoader.load('/textures/matcaps/7.png');
// const matcapTexture = textureLoader.load('/textures/matcaps/8.png');

// const gradientTexture = textureLoader.load('/textures/gradients/3.jpg');
const gradientTexture = textureLoader.load('/textures/gradients/5.jpg');

doorColorTexture.colorSpace = THREE.SRGBColorSpace;
matcapTexture.colorSpace = THREE.SRGBColorSpace;

// /**
//  * MeshBasicMaterial.
//  */
// const material = new THREE.MeshBasicMaterial();

// // Map can be specified in addition to a color in order to tint the texture.
// material.map = doorColorTexture;

// // All of these are equivalent for a color of "red".
// // material.color = new THREE.Color('#ff0000');
// // material.color = new THREE.Color('#f00');
// // material.color = new THREE.Color('red');
// // material.color = new THREE.Color('rgb(255, 0, 0)');
// // material.color = new THREE.Color(0xff0000);

// // Thin white lines regardless of distance to camera.
// // material.wireframe = true;

// // To have `opacity` work, you need to set `transparent` to true.
// // material.transparent = true;
// // material.opacity = 0.5;
// // Or you can use an alpha map, which also requires `transparent` to be true.
// material.alphaMap = doorAlphaTexture;

// // DoubleSide requires more resources even when the side isn't visible.
// material.side = THREE.DoubleSide;


// /**
//  * MeshNormalMaterial.
//  */
// const material = new THREE.MeshNormalMaterial();

// // See each face of the geometry.
// material.flatShading = true;


// /**
//  * MeshMatcapMaterial.
//  */
// const material = new THREE.MeshMatcapMaterial();
// material.matcap = matcapTexture;


// /**
//  * MeshDepthMaterial.
//  */
// const material = new THREE.MeshDepthMaterial();


// /**
//  * MeshLambertMaterial.
//  */
// const material = new THREE.MeshLambertMaterial();


// /**
//  * MeshPhongMaterial.
//  */
// const material = new THREE.MeshPhongMaterial();
// material.shininess = 100;
// material.specular = new THREE.Color(0x1188ff);


// /**
//  * MeshToonMaterial.
//  */
// const material = new THREE.MeshToonMaterial();
// gradientTexture.minFilter = THREE.NearestFilter;
// gradientTexture.magFilter = THREE.NearestFilter;
// // Since NearestFilter doesn't use mipmaps, we can get some performance back by
// // disabling them.
// gradientTexture.generateMipmaps = false;
// material.gradientMap = gradientTexture;


// /**
//  * MeshStandardMaterial.
//  */
// const material = new THREE.MeshStandardMaterial();
// // material.metalness = 0.7;
// // material.roughness = 0.2;
// material.metalnessMap = doorMetalnessTexture
// material.roughnessMap = doorRoughnessTexture
// // When specifying textures like above, you should set metalness and roughness
// // to 1 since these values will still apply on top of whatever textures you use.
// material.metalness = 1
// material.roughness = 1
// material.map = doorColorTexture;
// // Add shadows where the texture is dark. Only affects light from AmbientLight,
// // the environment map, and HemisphereLight.
// material.aoMap = doorAmbientOcclusionTexture;
// material.aoMapIntensity = 1;
// // Create relief from the height map...
// material.displacementMap = doorHeightTexture;
// // ... but that only looks good if you have enough vertices, so go change the
// // geometry to have more subdivisions.
// // ... and those vertices only look good if the displacement scale is correct.
// material.displacementScale = 0.1;
// // Fake the normal vectores regardless of subdivisions.
// material.normalMap = doorNormalTexture;
// material.normalScale.set(1, 1)
// material.transparent = true;
// material.alphaMap = doorAlphaTexture;


/**
 * MeshPhysicalMaterial.
 */
const material = new THREE.MeshPhysicalMaterial();
material.metalness = 0;
material.roughness = 0;
// material.map = doorColorTexture;
// material.aoMap = doorAmbientOcclusionTexture;
// material.aoMapIntensity = 1;
// material.displacementMap = doorHeightTexture;
// material.displacementScale = 0.1;
// material.metalnessMap = doorMetalnessTexture;
// material.roughnessMap = doorRoughnessTexture;
// material.normalMap = doorNormalTexture;
// material.normalScale.set(0.5, 0.5);


/**
 * Environment map.
 */
const rgbeLoader = new RGBELoader();
rgbeLoader.load('/textures/environmentMap/2k.hdr', (environmentMap) => {
  // console.log('environmentMap:', environmentMap);
  environmentMap.mapping = THREE.EquirectangularReflectionMapping;
  scene.background = environmentMap;
  scene.environment = environmentMap;
});



/**
 * Objects.
 */

const sphere = new THREE.Mesh(
  new THREE.SphereGeometry(
    0.5,  // Radius.
    64,   // Width segments.
    64,   // Height segments.
    // 16,   // Width segments.
    // 16,   // Height segments.
  ),
  material,
);
sphere.position.x = -1.5;
DebugUi.debugMesh(
  gui,
  sphere,
  DebugUi.createMeshConfig({
    meshName: 'sphere',
  }),
);

const plane = new THREE.Mesh(
  new THREE.PlaneGeometry(
    1,  // Width.
    1,  // Height.
    100,  // Width segments.
    100,  // Height segments.
  ),
  material,
);
DebugUi.debugMesh(
  gui,
  plane,
  DebugUi.createMeshConfig({
    meshName: 'plane',
  }),
);

const torus = new THREE.Mesh(
  new THREE.TorusGeometry(
    0.3,  // Radius.
    0.2,  // Tube radius.
    // 16,   // Radial segments.
    // 32,   // Tubular segments.
    64,   // Radial segments.
    128,   // Tubular segments.
  ),
  material,
);
torus.position.x = 1.5;
DebugUi.debugMesh(
  gui,
  torus,
  DebugUi.createMeshConfig({
    meshName: 'torus',
  }),
);

scene.add(sphere, plane, torus);


// /**
//  * Lights.
//  */
// const ambientLight = new THREE.AmbientLight(
//   0xffffff,  // Color.
//   1,  // Intensity.
// );
// scene.add(ambientLight);

// const pointLight = new THREE.PointLight(
//   0xffffff,  // Color.
//   30,  // Intensity.
// );
// pointLight.position.x = 2;
// pointLight.position.y = 3;
// pointLight.position.z = 4;
// scene.add(pointLight);


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

  // Rotate each object.
  sphere.rotation.y = elapsedTime * 0.1;
  plane.rotation.y = elapsedTime * 0.1;
  torus.rotation.y = elapsedTime * 0.1;

  sphere.rotation.x = elapsedTime * 0.1;
  plane.rotation.x = elapsedTime * 0.1;
  torus.rotation.x = elapsedTime * 0.1;

  // Render
  renderer.render(scene, camera)

  // Call tick again on the next frame
  window.requestAnimationFrame(tick)
}

tick()
