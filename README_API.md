# API REST (Crow) - DPDS

Requisitos:
- Instalar la librería Crow (single-header `crow_all.h`) y la biblioteca `nlohmann/json`.

Opciones de instalación (ejemplo):

1) Usando apt (si está disponible) o paquetes del sistema para `nlohmann-json-dev`.

2) Incluir Crow single-header (copiar `crow_all.h` a un include path) y usar `nlohmann/json.hpp` desde paquete del sistema o submódulo.

Build:

```bash
make api_server
```

Run:

```bash
./api_server 18080
```

Ejemplos `curl`:

- Listar experimentos:

```bash
curl http://localhost:18080/experimentos
```

- Crear experimento:

```bash
curl -X POST -H "Content-Type: application/json" -d '{"nombre":"exp1","descripcion":"desc"}' http://localhost:18080/experimentos
```

Notas:
- Este proyecto añade un servidor minimal que usa la fábrica `FabricaSistema` para obtener la instancia de `IExperimento` y expone endpoints básicos. Completar serializadores y endpoints adicionales según las necesidades del cliente web.