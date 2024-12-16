import * as THREE from 'three'
import GUI from 'lil-gui'

/**
 * This file provides helpers for creating a debug UI.
 *
 * I expect that you will either copy this file directly into your project OR
 * use a hardlink (specifically *not* a symlink) to this file in your project.
 * I do it this way so that many different lessons can benefit from the same
 * debug UI code.
 *
 * If you import this into a project, you must also `npm install lil-gui`.
 */

// Create a new GUI instance with optional config input.
export function createGuiConfig({
  title = 'Debug Ui',
  width = 300,
  closeFolders = true,
  closeGui = false,
} = {}) {
  return {
    title,
    width,
    closeFolders,
    closeGui,
  };
}
export function createGui(guiConfig = createGuiConfig()) {
  let gui = new GUI({
    title: guiConfig.title,
    width: guiConfig.width,
    closeFolders: guiConfig.closeFolders,
  });
  if (guiConfig.closeGui) {
    gui.close();
  }
  return gui;
}

// Create a new folder with the given GUI.
export function createFolder(gui, folderName) {
  return gui.addFolder(folderName);
}

// Add debug options for a mesh with optional config input.
export function createPositionConfig({
  xMin = -5,
  xMax = 5,
  yMin = -5,
  yMax = 5,
  zMin = -5,
  zMax = 5,
  step = 0.01,
} = {}) {
  return {
    xMin,
    xMax,
    yMin,
    yMax,
    zMin,
    zMax,
    step,
  };
}
export function createMeshConfig({
  meshName = 'Mesh',
  folder = null,
  subdivisions = 1,
  side = THREE.FrontSide,
  positionConfig = createPositionConfig(),
} = {}) {
  return {
    meshName,
    subdivisions,
    folder,
    positionConfig,
  };
}
export function debugMesh(
  gui,
  mesh,
  config = createMeshConfig(),
) {
  let folder = config.folder;
  if (folder === null) {
    folder = gui.addFolder(config.meshName);
  }
  folder.add(mesh, 'visible');
  folder.add(mesh.material, 'wireframe');
  // Only add subdivisions if this is a box since we have to recreate the
  // geometry and I don't yet know how to use a constructor for a generic
  // geometry type.
  if (mesh.geometry.type === 'BoxGeometry') {
    folder.add(config, 'subdivisions')
          .min(1)
          .max(20)
          .step(1)
          .name('subdivisions')
          .onFinishChange(() => {
            mesh.geometry.dispose();
            mesh.geometry = new THREE.BoxGeometry(
              1,  // Width.
              1,  // Height.
              1,  // Depth.
              config.subdivisions,  // Width segments.
              config.subdivisions,  // Height segments.
              config.subdivisions,  // Depth segments.
            );
          });
  }
  folder.add(mesh.position, 'x')
        .min(config.positionConfig.xMin)
        .max(config.positionConfig.xMax)
        .step(config.positionConfig.step)
        .name('positionX');
  folder.add(mesh.position, 'y')
        .min(config.positionConfig.yMin)
        .max(config.positionConfig.yMax)
        .step(config.positionConfig.step)
        .name('positionY');
  folder.add(mesh.position, 'z')
        .min(config.positionConfig.zMin)
        .max(config.positionConfig.zMax)
        .step(config.positionConfig.step)
        .name('positionZ');
  // Debug for MeshBasicMaterial.
  if (mesh.material.type === 'MeshBasicMaterial') {
    // MeshNormalMaterial doesn't have a color property, so this debug UI is
    // pretty specific, it turns out. Condition that out of the UI.
    folder.addColor(mesh.material, 'color');
  }
  // Debug for MeshNormalMaterial.
  if (mesh.material.type === 'MeshNormalMaterial') {
    folder.add(mesh.material, 'flatShading')
          .onChange(() => {
            mesh.material.needsUpdate = true;
          });
  }
  // Debug for MeshPhongMaterial.
  if (mesh.material.type === 'MeshPhongMaterial') {
    folder.add(mesh.material, 'shininess').min(0).max(100);
  }
  // Debug for MeshStandardMaterial.
  if (mesh.material.type === 'MeshStandardMaterial') {
    folder.add(mesh.material, 'metalness').min(0).max(1).step(0.01);
    folder.add(mesh.material, 'roughness').min(0).max(1).step(0.01);
  }
  // Debug for MeshPhysicalMaterial.
  if (mesh.material.type === 'MeshPhysicalMaterial') {
    folder.add(mesh.material, 'clearcoat').min(0).max(1).step(0.01);
    folder.add(mesh.material, 'clearcoatRoughness').min(0).max(1).step(0.01);

    folder.add(mesh.material, 'sheen').min(0).max(1).step(0.01);
    folder.add(mesh.material, 'sheenRoughness').min(0).max(1).step(0.01);
    folder.addColor(mesh.material, 'sheenColor');

    folder.add(mesh.material, 'iridescence').min(0).max(1).step(0.01);
    folder.add(mesh.material, 'iridescenceIOR').min(1).max(2.33).step(0.01);
    folder.add(mesh.material.iridescenceThicknessRange, '0').min(1).max(1000).step(1);
    folder.add(mesh.material.iridescenceThicknessRange, '1').min(1).max(1000).step(1);

    folder.add(mesh.material, 'transmission').min(0).max(1).step(0.01);
    folder.add(mesh.material, 'ior').min(1).max(10).step(0.01);
    folder.add(mesh.material, 'thickness').min(0).max(1).step(0.01);
  }
  folder.add(mesh.material, 'side', {
    FrontSide: THREE.FrontSide,
    BackSide: THREE.BackSide,
    DoubleSide: THREE.DoubleSide,
  });
  folder.add(mesh.material, 'transparent');
  folder.add(mesh.material, 'opacity').min(0).max(1).step(0.01);
  folder.add(mesh.material, 'alphaMap', {
    None: null,
    alphaMap: mesh.material.alphaMap,
  });
  return folder;
}

// Collapse errything, keeping track of state.
export function folderCollapseToggle(gui) {
  gui.folders.forEach(folder => {
    if (folder._closed) {
      folder.open();
    } else {
      folder.close();
    }
  });
}

// Listeners.
export function listenKeystrokes(gui) {
  window.addEventListener('keydown', (event) => {
    if (event.key == 'd') {
      gui.show(gui._hidden);
    } else if (event.key == 'c') {
      folderCollapseToggle(gui);
    }
  });
}




















