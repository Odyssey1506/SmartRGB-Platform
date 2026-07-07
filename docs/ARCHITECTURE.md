# SmartRGB OS Architecture

Version: 1.0
Status: In Development

---

# Vision

SmartRGB OS is a modular firmware platform for ESP32-based RGBW lighting controllers.

The goal is to build firmware that is easy to extend, maintain, and reuse across multiple SmartRGB products.

---

# Design Principles

- Modular architecture
- Single Responsibility Principle
- Hardware abstraction
- Non-blocking firmware
- Data-driven design
- Scalable for future products

---

# Module Responsibilities

## Application

- Starts all modules
- Owns the firmware lifecycle
- Coordinates communication

---

## OutputDriver

Responsible only for PWM output.

Never knows:
- Zones
- Effects
- Animations

---

## LightingEngine

Responsible for:

- Zone management
- Effects
- Applying colors
- Communicating with OutputDriver

---

## SettingsManager

Responsible for:

- Saving settings
- Loading settings
- Flash storage

---

## HardwareConfig

Contains:

- GPIO mapping
- PWM frequency
- PWM resolution
- Hardware capabilities

---

# Firmware Layers

Application

↓

LightingEngine

↓

OutputDriver

↓

ESP32 LEDC

↓

LED Strip

---

# Current Features

✓ RGBW Output

✓ Two independent zones

✓ Modular Output Driver

✓ Zone abstraction

✓ Lighting Engine

---

# Planned Features

- Persistent settings
- Scenes
- Startup behaviour
- Animations
- Brightness engine
- Wi-Fi
- MQTT
- OTA Updates
- Mobile App