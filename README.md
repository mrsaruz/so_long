# so_long

[English](#english) | [Español](#español)

---

## English

### Description

so_long is a 42 project that consists of creating a small 2D game using a graphics library. This project introduces you to graphic design, event handling, textures, sprites, and basic game mechanics. The goal is to create a game where a character must collect all items on a map and reach the exit.

### Project objectives

- Work with a graphics library (MiniLibX or MLX42)
- Handle keyboard events
- Parse and validate map files
- Render 2D graphics with textures
- Implement basic game mechanics (movement, collision, win/lose conditions)
- Manage memory properly with no leaks

### Game components

The game must include the following elements:

| Character | Description |
|-----------|-------------|
| `1` | Wall |
| `0` | Empty space |
| `C` | Collectible (at least 1) |
| `E` | Exit (at least 1) |
| `P` | Player starting position (exactly 1) |

### Map requirements

#### Basic rules

- Maps must have a `.ber` extension
- The map must be rectangular
- The map must be surrounded by walls (`1`)
- The map must contain:
  - Exactly one player (`P`)
  - At least one exit (`E`)
  - At least one collectible (`C`)
- The map must have a valid path from the player to all collectibles and the exit

#### Map validation

Your program must validate:

1. **File format**: Must be a `.ber` file
2. **Rectangular shape**: All rows must have the same length
3. **Closed map**: Surrounded by walls on all sides
4. **Valid characters**: Only `0`, `1`, `C`, `E`, and `P`
5. **Required elements**: Exactly one `P`, at least one `C` and one `E`
6. **Valid path**: All collectibles and the exit must be reachable

If validation fails, the program must exit with `Error\n` followed by an explicit error message.

#### Example maps

**Valid map:**
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

**Invalid map (not rectangular):**
```
1111111111111
10010000000C1
1P0011E000001
1111111111111
```

### Mandatory requirements

#### Game mechanics

- The player can move in 4 directions using `W`, `A`, `S`, `D` or arrow keys
- The player cannot move through walls
- The player must collect all collectibles before the exit opens
- The current number of movements must be displayed in the shell
- Pressing `ESC` or clicking the window's close button exits the game cleanly

#### Graphics

- The game must display the map in a window
- Each tile must be clearly distinguishable
- Use textures/sprites for walls, floor, collectibles, player, and exit
- Smooth rendering without flickering

#### Technical requirements

- Use MiniLibX or MLX42 (depending on campus)
- No memory leaks
- Proper error handling
- Clean exit on all scenarios
- Program name: `so_long`
- Usage: `./so_long maps/map.ber`

### Compilation

```bash
# Clone the repository
git clone https://github.com/mrsaruz/so_long.git
cd so_long

# Compile the project
make

# Clean object files
make clean

# Clean everything
make fclean

# Recompile
make re
```

### Usage

#### Running the game

```bash
# Basic usage
./so_long maps/map.ber

# Test with different maps
./so_long maps/small.ber
./so_long maps/medium.ber
./so_long maps/large.ber
```

#### Controls

- `W` or `↑`: Move up
- `A` or `←`: Move left
- `S` or `↓`: Move down
- `D` or `→`: Move right
- `ESC`: Exit game

#### Gameplay

1. Navigate through the map using keyboard controls
2. Collect all items (`C`) on the map
3. Once all items are collected, the exit (`E`) becomes available
4. Reach the exit to win the game
5. Movement count is displayed in the terminal

### Project structure

```
so_long/
├── Makefile
├── include/
│   └── so_long.h
├── src/
│   ├── main.c
│   ├── map_parsing.c
│   ├── map_validation.c
│   ├── game_init.c
│   ├── game_render.c
│   ├── game_movement.c
│   ├── game_events.c
│   └── utils.c
├── textures/
│   ├── wall.png
│   ├── floor.png
│   ├── collectible.png
│   ├── player.png
│   └── exit.png
├── maps/
│   ├── map1.ber
│   ├── map2.ber
│   └── map3.ber
├── libft/
├── ft_printf/
├── get_next_line/
└── MLX42/
```

### Testing

#### Test cases

1. **Valid maps**: Test with correct maps of various sizes
2. **Invalid maps**: Test error handling for:
   - Non-rectangular maps
   - Maps without walls
   - Maps without required elements
   - Maps with invalid characters
   - Maps with no valid path
   - Non-`.ber` files
3. **Gameplay**: Test movement, collision, collection, and win conditions
4. **Memory**: Check for leaks with valgrind
5. **Edge cases**: Empty files, very large maps, special characters

#### Memory testing

```bash
valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/map.ber
```

### Tips

1. Start with map parsing and validation before graphics
2. Test your map validation thoroughly
3. Use modular functions for each game component
4. Keep your rendering loop efficient
5. Handle all edge cases in movement
6. Test with various map sizes and complexities
7. Use macros for tile size and keycodes
8. Document your code for better maintenance

### Common errors to avoid

- Not checking if collectibles are all gathered before allowing exit
- Forgetting to update movement counter
- Not handling window close event properly
- Memory leaks from textures/images
- Not validating map path (flood fill)
- Allowing diagonal movement
- Not handling ESC key properly

---

## Español

### Descripción

so_long es un proyecto de 42 que consiste en crear un pequeño juego 2D usando una librería gráfica. Este proyecto te introduce al diseño gráfico, manejo de eventos, texturas, sprites y mecánicas básicas de juego. El objetivo es crear un juego donde un personaje debe recolectar todos los objetos de un mapa y llegar a la salida.

### Objetivos del proyecto

- Trabajar con una librería gráfica (MiniLibX o MLX42)
- Manejar eventos de teclado
- Parsear y validar archivos de mapas
- Renderizar gráficos 2D con texturas
- Implementar mecánicas básicas de juego (movimiento, colisión, condiciones de victoria/derrota)
- Gestionar la memoria correctamente sin leaks

### Componentes del juego

El juego debe incluir los siguientes elementos:

| Carácter | Descripción |
|----------|-------------|
| `1` | Muro |
| `0` | Espacio vacío |
| `C` | Coleccionable (al menos 1) |
| `E` | Salida (al menos 1) |
| `P` | Posición inicial del jugador (exactamente 1) |

### Requisitos del mapa

#### Reglas básicas

- Los mapas deben tener extensión `.ber`
- El mapa debe ser rectangular
- El mapa debe estar rodeado de muros (`1`)
- El mapa debe contener:
  - Exactamente un jugador (`P`)
  - Al menos una salida (`E`)
  - Al menos un coleccionable (`C`)
- El mapa debe tener un camino válido desde el jugador hasta todos los coleccionables y la salida

#### Validación del mapa

Tu programa debe validar:

1. **Formato de archivo**: Debe ser un archivo `.ber`
2. **Forma rectangular**: Todas las filas deben tener la misma longitud
3. **Mapa cerrado**: Rodeado de muros por todos lados
4. **Caracteres válidos**: Solo `0`, `1`, `C`, `E` y `P`
5. **Elementos requeridos**: Exactamente un `P`, al menos un `C` y un `E`
6. **Camino válido**: Todos los coleccionables y la salida deben ser alcanzables

Si la validación falla, el programa debe terminar con `Error\n` seguido de un mensaje de error explícito.

#### Mapas de ejemplo

**Mapa válido:**
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

**Mapa inválido (no rectangular):**
```
1111111111111
10010000000C1
1P0011E000001
1111111111111
```

### Requisitos obligatorios

#### Mecánicas del juego

- El jugador puede moverse en 4 direcciones usando `W`, `A`, `S`, `D` o las flechas
- El jugador no puede atravesar muros
- El jugador debe recolectar todos los coleccionables antes de que se abra la salida
- El número actual de movimientos debe mostrarse en la terminal
- Presionar `ESC` o hacer clic en el botón de cerrar de la ventana cierra el juego correctamente

#### Gráficos

- El juego debe mostrar el mapa en una ventana
- Cada casilla debe ser claramente distinguible
- Usar texturas/sprites para muros, suelo, coleccionables, jugador y salida
- Renderizado suave sin parpadeos

#### Requisitos técnicos

- Usar MiniLibX o MLX42 (dependiendo del campus)
- Sin leaks de memoria
- Manejo adecuado de errores
- Salida limpia en todos los escenarios
- Nombre del programa: `so_long`
- Uso: `./so_long maps/map.ber`

### Compilación

```bash
# Clonar el repositorio
git clone https://github.com/mrsaruz/so_long.git
cd so_long

# Compilar el proyecto
make

# Limpiar archivos objeto
make clean

# Limpiar todo
make fclean

# Recompilar
make re
```

### Uso

#### Ejecutar el juego

```bash
# Uso básico
./so_long maps/map.ber

# Probar con diferentes mapas
./so_long maps/small.ber
./so_long maps/medium.ber
./so_long maps/large.ber
```

#### Controles

- `W` o `↑`: Mover arriba
- `A` o `←`: Mover izquierda
- `S` o `↓`: Mover abajo
- `D` o `→`: Mover derecha
- `ESC`: Salir del juego

#### Cómo jugar

1. Navega por el mapa usando los controles del teclado
2. Recolecta todos los objetos (`C`) en el mapa
3. Una vez recolectados todos los objetos, la salida (`E`) se vuelve disponible
4. Alcanza la salida para ganar el juego
5. El contador de movimientos se muestra en la terminal

### Estructura del proyecto

```
so_long/
├── Makefile
├── include/
│   └── so_long.h
├── src/
│   ├── main.c
│   ├── map_parsing.c
│   ├── map_validation.c
│   ├── game_init.c
│   ├── game_render.c
│   ├── game_movement.c
│   ├── game_events.c
│   └── utils.c
├── textures/
│   ├── wall.png
│   ├── floor.png
│   ├── collectible.png
│   ├── player.png
│   └── exit.png
├── maps/
│   ├── map1.ber
│   ├── map2.ber
│   └── map3.ber
├── libft/
├── ft_printf/
├── get_next_line/
└── MLX42/
```

### Testing

#### Casos de prueba

1. **Mapas válidos**: Probar con mapas correctos de varios tamaños
2. **Mapas inválidos**: Probar manejo de errores para:
   - Mapas no rectangulares
   - Mapas sin muros
   - Mapas sin elementos requeridos
   - Mapas con caracteres inválidos
   - Mapas sin camino válido
   - Archivos no `.ber`
3. **Jugabilidad**: Probar movimiento, colisión, recolección y condiciones de victoria
4. **Memoria**: Verificar leaks con valgrind
5. **Casos edge**: Archivos vacíos, mapas muy grandes, caracteres especiales

#### Testing de memoria

```bash
valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/map.ber
```

### Consejos

1. Comienza con el parseo y validación de mapas antes de los gráficos
2. Prueba tu validación de mapas exhaustivamente
3. Usa funciones modulares para cada componente del juego
4. Mantén tu bucle de renderizado eficiente
5. Maneja todos los casos edge en el movimiento
6. Prueba con varios tamaños y complejidades de mapas
7. Usa macros para el tamaño de las casillas y códigos de teclas
8. Documenta tu código para mejor mantenimiento

### Errores comunes a evitar

- No verificar si todos los coleccionables están recolectados antes de permitir salir
- Olvidar actualizar el contador de movimientos
- No manejar el evento de cerrar ventana correctamente
- Leaks de memoria por texturas/imágenes
- No validar el camino del mapa (flood fill)
- Permitir movimiento diagonal
- No manejar la tecla ESC correctamente

---

## Author / Autor

adruz-to - 42 Málaga

## License / Licencia

This project is part of the 42 curriculum. / Este proyecto es parte del curriculum de 42.
