#include "B1DetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1DetectorConstruction::B1DetectorConstruction()
: G4VUserDetectorConstruction(),
  fScoringVolume(0)
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1DetectorConstruction::~B1DetectorConstruction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* B1DetectorConstruction::Construct()
{
  // Get nist material manager
  G4NistManager* nist = G4NistManager::Instance();


  // Option to switch on/off checking of volumes overlaps
  //
  G4bool checkOverlaps = true;

  //
  // World
  //
  G4double world_sizeX = 200*cm;
  G4double world_sizeY = 70*cm;
  G4double world_sizeZ  = 60*cm;
  G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR");

  G4Box* solidWorld =
    new G4Box("World",                       //its name
       0.5*world_sizeX, 0.5*world_sizeY, 0.5*world_sizeZ);     //its size

  G4LogicalVolume* logicWorld =
    new G4LogicalVolume(solidWorld,          //its solid
                        world_mat,           //its material
                        "World");            //its name

  G4VPhysicalVolume* physWorld =
    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(),       //at (0,0,0)
                      logicWorld,            //its logical volume
                      "World",               //its name
                      0,                     //its mother  volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      checkOverlaps);        //overlaps checking

  //
  // Scint1
  //
  G4Material* scint_mat = nist->FindOrBuildMaterial("G4_WATER");
  G4ThreeVector pos1 = G4ThreeVector(0.*cm, 0.*cm, 0*cm);

  G4double scint_x = 99.2*cm;
  G4double scint_y = 1.2*cm;
  G4double scint_z = 11.3*cm;
  G4Box* scint1 =
    new G4Box("Scintillator1", 0.5*scint_x, 0.5*scint_y, 0.5*scint_z);

  G4LogicalVolume* logicScint1 =
    new G4LogicalVolume(scint1,         //its solid
                        scint_mat,          //its material
                        "Scintillator1");           //its name

  new G4PVPlacement(0,                       //no rotation
                    pos1,                    //at position
                    logicScint1,             //its logical volume
                    "Scintillator1",                //its name
                    logicWorld,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking

  //
  // Fe1
  //
  G4Material* iron_mat = nist->FindOrBuildMaterial("G4_Fe");
  G4ThreeVector pos2 = G4ThreeVector(0.*cm, 16.6*cm, 0.0*cm);

  G4double iron_x = 150.0*cm;
  G4double iron_y = 0.5*cm;
  G4double iron_z = 30.0*cm;
  G4Box* iron1 =
    new G4Box("iron1", 0.5*iron_x, 0.5*iron_y, 0.5*iron_z);

  G4LogicalVolume* logicIron1 =
    new G4LogicalVolume(iron1,         //its solid
                        iron_mat,          //its material
                        "iron1");           //its name

  new G4PVPlacement(0,                       //no rotation
                    pos2,                    //at position
                    logicIron1,             //its logical volume
                    "iron1",                //its name
                    logicWorld,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking

  //
  // Scint2
  //
  G4ThreeVector pos3 = G4ThreeVector(0.*cm, 32.2*cm, 0*cm);

  scint_x = 118.5*cm;
  scint_y = 1.2*cm;
  scint_z = 11.3*cm;
  G4Box* scint2 =
    new G4Box("Scintillator2", 0.5*scint_x, 0.5*scint_y, 0.5*scint_z);

  G4LogicalVolume* logicScint2 =
    new G4LogicalVolume(scint2,         //its solid
                        scint_mat,          //its material
                        "Scintillator2");           //its name

  new G4PVPlacement(0,                       //no rotation
                    pos3,                    //at position
                    logicScint2,             //its logical volume
                    "Scintillator2",                //its name
                    logicWorld,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking

  //
  // Scint3
  //
  G4ThreeVector pos4 = G4ThreeVector(0.*cm, 47.8*cm, 0*cm);

  scint_x = 73.4*cm;
  scint_y = 1.2*cm;
  scint_z = 11.3*cm;
  G4Box* scint3 =
    new G4Box("Scintillator3", 0.5*scint_x, 0.5*scint_y, 0.5*scint_z);

  G4LogicalVolume* logicScint3 =
    new G4LogicalVolume(scint3,         //its solid
                        scint_mat,          //its material
                        "Scintillator3");           //its name

  new G4PVPlacement(0,                       //no rotation
                    pos4,                    //at position
                    logicScint3,             //its logical volume
                    "Scintillator3",                //its name
                    logicWorld,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking

  //
  // Fe2
  //
  G4ThreeVector pos5 = G4ThreeVector(0.*cm, 62.0*cm, 0.0*cm);

  iron_x = 73.4*cm;
  iron_y = 5.1*cm;
  iron_z = 40.0*cm;
  G4Box* iron2 =
    new G4Box("iron2", 0.5*iron_x, 0.5*iron_y, 0.5*iron_z);

  G4LogicalVolume* logicIron2 =
    new G4LogicalVolume(iron2,         //its solid
                        iron_mat,          //its material
                        "iron2");           //its name

  new G4PVPlacement(0,                       //no rotation
                    pos5,                    //at position
                    logicIron2,             //its logical volume
                    "iron2",                //its name
                    logicWorld,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking

  //
  // Fe3
  //
  G4ThreeVector pos6 = G4ThreeVector(0.*cm, 83.0*cm, 0.0*cm);

  iron_x = 90.0*cm;
  iron_y = 20.8*cm;
  iron_z = 40.0*cm;
  G4Box* iron3 =
    new G4Box("iron3", 0.5*iron_x, 0.5*iron_y, 0.5*iron_z);

  G4LogicalVolume* logicIron3 =
    new G4LogicalVolume(iron3,         //its solid
                        iron_mat,          //its material
                        "iron3");           //its name

  new G4PVPlacement(0,                       //no rotation
                    pos6,                    //at position
                    logicIron3,             //its logical volume
                    "iron3",                //its name
                    logicWorld,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking

  // Set Shape2 as scoring volume
  //
  fScoringVolume = logicIron1;

  //
  //always return the physical World
  //
  return physWorld;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
