# Spool-Roller

<img src="https://github.com/user-attachments/assets/d2e98978-cee0-49f3-8675-edde1e05f2f9" alt="WhatsApp Image" width="300">



# Device Function Description

The device is designed for winding various materials, such as wire, filament, or cable.  
The basic principle is based on two main components:

- **Guide Unit**: Moves smoothly back and forth to ensure the material is wound neatly and in parallel.  
- **Drive Roller**: Winds the material onto the spool.

This technology allows spools to be filled automatically and evenly.

---

## Operating Modes

### 1. Automatic Mode

The user specifies the following parameters:

- Number of windings  
- Wire diameter  
- Spool width  

The winding process is fully automated according to the set values.  
This mode is particularly suitable for manufacturing custom spools, such as induction coils.

---

### 2. Manual Mode

- No input of winding data required.  
- The winding speed is manually controlled via a rotary knob.

---

## Operating Instructions

### 1. Preparation

1. Power on the device.  
2. Select one of the two operating modes (Automatic or Manual) via the menu.  
3. If necessary, set the parameters (e.g., winding count, wire diameter, spool width).  

**Note:** During parameter entry, all motors are disabled and mechanically free to move.

---

### 2. Guide Zeroing

1. After entering the parameters, move the guide to the left edge of the guide rail.  
2. This position is set as the zero point.

---

### 3. Spool Preparation

1. Mount an empty spool on the device.  
   - The clamping mechanism works similarly to a lathe chuck.  
2. Thread the material (e.g., wire, filament, or cable) through the guide.  
3. Secure the material end firmly to the spool.  
4. Apply light tension to the material to ensure neat winding.

---

### 4. Starting the Winding Process

After zeroing, the selected operating mode starts automatically:

- **Automatic Mode:** Winding is performed according to the set parameters.  
- **Manual Mode:** Winding speed is controlled via the rotary knob.

---

## Software and Control Layout

### Control Concept

**Control Element:**  
All menu items are controlled via a rotary knob with a push function.

- **Rotate:** Navigate between menu items  
- **Push:** Select a menu item or confirm an entry  

**Display:**  
An OLED display shows all available functions, menus, and status messages of the device.

---

## Device Control

- **Main Switch:** Located on the device housing for turning the entire unit on/off.  
- **Power Supply:**  
  - Power adapter: 12 V, minimum 3 A output  
  - Power consumption: approx. 1.8 A during operation  

---

## Electronics Layout

- **Central Control Unit:**  
  - ESP32 microcontroller for motor control, display management, and user interaction  

- **Motor Drivers:**  
  - Two separate drivers for controlling the different motors  

- **Power Conversion:**  
  - DC-to-DC voltage converters for internal circuits and voltage adjustment  

---
