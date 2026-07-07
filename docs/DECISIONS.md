# SmartRGB Architecture Decisions

## ADR-001

Application coordinates all modules.

Reason:

Keeps modules independent.

---

## ADR-002

OutputDriver only controls hardware.

Reason:

Hardware abstraction.

---

## ADR-003

LightingEngine owns lighting logic.

Reason:

Separates hardware from lighting behaviour.

---

## ADR-004

Animations restart after power loss.

Reason:

Users care about restoring the effect, not the animation frame.

---

## ADR-005

Startup behaviour is configurable.

Options:

- Restore Previous State
- Factory Default
- Always Off
- Custom Startup Scene

Reason:

Provides flexibility for residential and commercial installations.

---

## ADR-006

Persistent settings and runtime state are separate.

Reason:

Runtime data changes every frame and should never be written to flash.