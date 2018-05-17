# collapsibleQTabWidget
Pestañas plegables basadas en QTabWidget ( Folding tabs based on QTabWidget )
Solo funciona correctamente con TabPosition::North, para TabPosition::South el comportamiento no es el deseable y como la documentación lo dice, "Los widgets de esquina están diseñados para las posiciones de pestañas norte y sur; se sabe que otras orientaciones no funcionan correctamente.", y este intento por extender funcionalidades al QTabWidget no es la excepción, por lo que las posiciones TabPosition::West y TabPosition::East no funcionan (It only works correctly with TabPosition::North, for TabPosition::South the behavior is not desirable and as the documentation says, "Corner widgets are designed for north and south tab positions, it is known that other orientations do not work correctly.", and this attempt to extend features to the QTabWidget is no exception, so the TabPosition::West and TabPosition::East positions do not work).

### TODO

- [ ] Adaptar el código para poder ser utilizado desde QtDesigner (Adapt the code to be used from QtDesigner).
- [ ] Adaptar el código a qt-plugin-system (Adapt the code to qt-plugin-system).
- [ ] Hacer de forma transparente, que al colapsar el QTabWidget se redimensione su contenedor padre (Make it transparent, so that when the QTabWidget collapses its parent container is resized). Al colapsar el QTabWidget, permitir se redimensione el contenedor padre no está implementado aun (When the QTabWidget collapses, allowing the parent container to be resized is not implemented yet).
- [ ] Documentar el código (Document the code).
- [x] Falta ajustar la animación después de modificada las dimensiones del QTabWidget (The animation needs to be adjusted after the dimensions of the QTabWidget have been modified).
