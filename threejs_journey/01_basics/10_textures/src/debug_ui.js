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
  folder.addColor(mesh.material, 'color');
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




















