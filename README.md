# Trabajo Práctico  3

Este proyecto corresponde al TP3 de la Especialización en Sistemas Embebidos de la FIUBA, que se centra en el desarrollo de tests unitarios utilizando Ceedling. Este archivo README describe el propósito del proyecto, el enfoque de desarrollo con TDD y detalles sobre la estructura del repositorio y la ejecución de las pruebas.

## Autor
Marco Rolón Radcenco

## Objetivo del Proyecto
El objetivo de este proyecto es desarrollar y probar un componente específico del software del robot MIRA, mediante pruebas unitarias. La metodología de desarrollo empleada es TDD (Test-Driven Development), asegurando que cada función esté completamente testeada antes de su implementación en la producción. Esto ayuda a garantizar la calidad del software y facilita el mantenimiento y escalabilidad del código.

## Enfoque de Desarrollo
Este proyecto sigue un enfoque de TDD, donde los tests se escriben antes de la implementación de la funcionalidad. Los casos de prueba cubren tanto escenarios comunes como excepcionales y aseguran que cada función cumpla con los requisitos esperados. Además, se prioriza la creación de funciones de tests cortas y específicas para mantener la claridad y eficacia del proceso de testing.

## Estructura de la Prueba
Se desarrollaron 10 casos de prueba para cubrir el funcionamiento del módulo seleccionado. Estos casos incluyen validaciones de límites, pruebas de comportamiento en condiciones normales y excepcionales, y verificaciones de parámetros críticos.

## Componentes Probados
El componente elegido es el módulo de control de movimiento del robot MIRA. Este módulo es fundamental para la ejecución de las instrucciones de movimiento, y los tests aseguran que los cálculos de cinemática y control de motores sean correctos. Se incluyeron funciones de verificación de seguridad específicas, como por ejemplo, control de ángulos y detección de botones de emergencia.

## Herramientas Utilizadas

 - Ceedling: Framework de testing unitario empleado para desarrollar y ejecutar los tests.
 - Git: Control de versiones para el seguimiento del código fuente y los tests.
 - Doxygen: Utilizado para documentar las funciones de manera estructurada y facilitar su comprensión.

## Ejecución de las Pruebas
Para ejecutar los tests, seguir estos pasos:

 - Clonar el repositorio.
 - Navegar a la carpeta del proyecto.
 - Correr el comando ceedling test:all en la terminal para ejecutar todas las pruebas.
