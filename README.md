Funcionalidades. El programa contará con un menú con las siguientes opciones:
Menú Principal
1. Agregar Tareas
2. Buscar Tarea
3. Mostrar todas las tareas
4. Eliminar Tarea
5. Salir del Programa

1. Agregar Tareas
• El usuario puede agregar entre 1 y 5 tareas como máximo.
• Se debe solicitar la siguiente información para cada tarea:
1. Código de la tarea (valor numérico de 4 dígitos)
2. Nombre de la tarea (texto descriptivo)
3. Fecha de vencimiento en formato dd/mm/aaaa
4. Hora de inicio en formato hh:mm
5. Hora de finalización en formato hh:mm
• Es obligatorio que todos los campos estén completos; no se aceptarán valores vacíos.
• Se deben validar los datos de fecha y hora, en el formato que se describe, y mostrar un
mensaje de error en caso de no cumplir con dicho formato.
II Cuatrimestre 2025 Página 2 de 9
[Introducción a la Programación] exitosamente”
.
Código: 
• Una vez registrada la tarea correctamente, se debe mostrar el mensaje: “Tarea agregada
• Mostrar un mensaje para regresar al menú principal, en caso de ser Si (S), vuelve al
menú: en caso de ser No (N), puede iniciar nuevamente el proceso para agregar tareas.
• La única forma de salir del programa es através de la opción “Salir del Programa”
---------------------------------------------
Ingrese la cantidad de tareas que desea agregar:
---------------------------------------------
Número de código tarea 1 (4 dígitos):________
Nombre de la tarea : ________________________
Fecha de vencimiento (dd/mm/aaaa):___________
Hora de inicio (hh:mm) : _________
Hora de finalización (hh:mm) : _________
Desea regresar al menú principal (S/N):

2. Buscar Tarea:
• Solicitar al usuario el código de la tarea que desea buscar.
• Verificar si la tarea existe en el registro.
• Si la tarea es encontrada, mostrar la siguiente información:
1. Nombre de la tarea,
2. Fecha de vencimiento (dd/mm/aaaa)
3. Duración de la tarea en minutos. (Debe realizar el cálculo de forma
automática, considerando la hora inicio y la hora fin)
• Si la tarea no se encuentra, mostrar el mensaje: “Tarea no encontrada”
Ejemplo de entrada y salida:
Ingrese el código de la tarea a buscar: 1234
+------------+----------------------------+----------------------------------+---------------------------+
| Código | Nombre | Fecha Vencimiento | Minutos invertidos |
+------------+----------------------------+----------------------------------+----------------------------+
| 1234 | Clasificar material | 20/02/2025 | 75 |
+------------+----------------------------+-----------------------------------+----------------------------+
Opción 3: Mostrar Todas las Tareas
• Regla: Se deben listar todas las tareas almacenadas en el sistema.
• Validación: Antes de mostrar las tareas, verificar si hay registros disponibles.
II Cuatrimestre 2025 Página 3 de 9
[Introducción a la Programación] • Si no hay tareas registradas, mostrar el mensaje “No hay tareas
registradas” y vuelve al menú principal.
Código: [00831]
• Si existen tareas almacenadas, mostrar la información en el siguiente
formato:
Lista de todas las tareas:
+------------+----------------------------+----------------------------+--------------------------+
| Código | Nombre | Fecha Vencimiento | Minutos invertidos |
+------------+----------------------------+----------------------------+--------------------------+
| 1234 | Clasificar material | 20/02/2025 | 35 |
| 6543 | Elaborar ensayo | 21/02/2025 | 148 |
| 5555 | Entregar ensayo | 22/02/2025 | 10 |
+------------+----------------------------+-----------------------------+--------------------------+

4. Eliminar Tarea
• Solicitar al usuario el código de la tarea que desea eliminar.
• Verificar si la tarea existe en el sistema antes de eliminarla.
• Si la tarea existe, solicitar confirmación con el siguiente mensaje: “¿Está
seguro de que desea eliminar la tarea [Nombre de la tarea]?,(S/N).
• Si el usuario ingresa “S”, eliminar la tarea y mostrar el mensaje:
“Tarea eliminada exitosamente”
• Si el usuario ingresa “N”, cancelar la acción y regresar al menú
principal.

5. Salir del Programa
• Esta opción finaliza la ejecución del sistema.
El sistema debe utilizar ciclos (estructuras de control o bucles) y variables (enteras) para el
manejo de los datos, adicionalmente, puede utilizar constantes para los porcentajes y rangos,
así como estructuras de datos.
II Cuatrimestre 2025 Página 4 de 9
[Introducción a la Programación] Codificación:
Código: [00831]
• El menú debe incluir únicamente las opciones indicadas (1-2-3-4-5), sin omitir ni agregar
opciones adicionales. Además, debe validar que solo permita ingresar valores
numéricos dentro de este rango, evitando el uso de letras u otros caracteres
especiales.
• El programa debe ser compatible con caracteres especiales, permitiendo mostrar las letras
con tildes y los caracteres como la “ñ”.
• Si el usuario digite un valor fuera del rango del menú, se debe mostrar el mensaje de:
“Opción inválida, vuelva a intentarlo” y solicitar nuevamente una opción válida.
• En la opción “Agregar Tareas”, todos los campos son obligatorios. En caso de que no ingrese
un valor, debe de programar lo necesario para que el campo sea requerido, todos los
campos son requeridos.
• Si no ha ingresado datos previamente, cuando ingrese a las opciones 2-3-4, debe
desplegar un mensaje que indique “Debe ingresar primero la tarea” y devolverlo al menú
principal.
• Deben existir validaciones con los datos que se ingresan:
a. b. c. d. e. f. El menú solo debe permitir opciones numéricas (1 a 5). Si se ingresa un valor inválido,
debe mostrar "Opción inválida, vuelva a intentarlo".
Al registrar tareas, si un campo está vacío, debe solicitarse nuevamente.
La cantidad de tareas debe estar en el rango de 1 a 5. Si el valor está fuera de este
rango, mostrar "Cantidad de tareas fuera de rango".
El número de código debe tener exactamente 4 dígitos y ser numérico.
El nombre de la tarea debe permitir varias palabras “cadena de caracteres”
.
Las opciones que despliegue aceptar "S" o "N" (convertir minúsculas a mayúsculas
automáticamente).
• El menú debe mostrarse de forma continua hasta que el usuario ingrese el valor de salida
#5. Es decir, la única forma de finalizar el programa es regresando al menú principal y
eligiendo la opción #5 para Salir.