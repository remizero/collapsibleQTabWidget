# collapsibleQTabWidget
Pestañas plegables basadas en QTabWidget ( Folding tabs based on QTabWidget ).

Solo funciona correctamente con TabPosition::North, para TabPosition::South el comportamiento no es el deseable y como la documentación lo dice, "Los widgets de esquina están diseñados para las posiciones de pestañas norte y sur; se sabe que otras orientaciones no funcionan correctamente.", y este intento por extender funcionalidades al QTabWidget no es la excepción, por lo que las posiciones TabPosition::West y TabPosition::East no funcionan.

(It only works correctly with TabPosition::North, for TabPosition::South the behavior is not desirable and as the documentation says, "Corner widgets are designed for north and south tab positions, it is known that other orientations do not work correctly.", and this attempt to extend features to the QTabWidget is no exception, so the TabPosition::West and TabPosition::East positions do not work).

### TODO

- [x] La animación necesita ser ajustada después que las dimensiones del QTabWidget han sido modificadas (The animation needs to be adjusted after the dimensions of the QTabWidget have been modified).
- [ ] Adaptar el código para poder ser utilizado desde QtDesigner (Adapt the code to be used from QtDesigner).
- [ ] Adaptar el código a qt-plugin-system (Adapt the code to qt-plugin-system).
- [ ] Hacer de forma transparente, que al colapsar el QTabWidget se redimensione su contenedor padre (Make it transparent, so that when the QTabWidget collapses its parent container is resized). Al colapsar el QTabWidget, permitir se redimensione el contenedor padre no está implementado aun (When the QTabWidget collapses, allowing the parent container to be resized is not implemented yet).
- [ ] Documentar el código (Document the code).
- [x] Ajustar el comportamiento/animación del botón de la esquina de acuerdo a la posición Izquierda/Derecha ( Adjust the behavior / animation of the corner button according to the Left / Right position ).
- [x] Ajustar el comportamiento/animación del botón de la esquina de acuerdo a la posición de las pestañas Norte/Sur ( Adjust the behavior / animation of the corner button according to the position of the North / South tabs. ).
- [ ] Permitir arrastrar y soltar pestañas y convertirlas en una ventana flotante ( Allow drag and drop tabs and turn them into a floating window ).
- [ ] Permitir convertir pestañas y convertirlas en una ventana flotante la hacer docle click, este punto excluye al punto siguiente ( Allow to convert tabs and turn them into a floating window do click click, this point excludes the next point ).
- [ ] Permitir colapsar/descolapsar las pestañas al hacer doble click, este punto excluye al punto anterior ( Allow collapsing/uncollapsing the tabs by double clicking, this point excludes the previous point ).
