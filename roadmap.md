# Roadmap de proyectos de utilidades para Linux

Este archivo es una **lista TODO** de proyectos prácticos para familiarizarse con Linux, su filesystem, procesos y herramientas base.
Cada proyecto incluye **subobjetivos técnicos** que sirven como guía de implementación.

---

## 1. `ls` extendido (mini coreutils)

* [ ] Listar contenido de un directorio
* [ ] Ignorar `.` y `..`
* [ ] Obtener tipo de archivo (`stat` / `lstat`)
* [ ] Mostrar permisos (`rwx`)
* [ ] Mostrar owner y grupo
* [ ] Mostrar tamaño en bytes
* [ ] Opción `-a` (mostrar ocultos)
* [ ] Opción `-l` (formato largo)
* [ ] Opción `-h` (tamaños humanos)
* [ ] Ordenar por nombre
* [ ] Ordenar por tamaño / fecha

Aprendizaje clave:

* Jerarquía del filesystem
* Inodos, permisos, links

---

## 2. Analizador de uso de disco (`du` + `df`)

* [ ] Recorrer directorios recursivamente
* [ ] Sumar tamaños de archivos
* [ ] Manejar hardlinks correctamente
* [ ] Mostrar tamaño total por directorio
* [ ] Leer información de FS (`statfs`)
* [ ] Mostrar espacio libre / usado
* [ ] Detectar puntos de montaje
* [ ] Excluir FS virtuales (`proc`, `sys`, `tmpfs`)

Aprendizaje clave:

* Filesystems
* Montajes
* Espacio en disco real

---

## 3. Buscador de archivos

* [ ] Recorrer directorios recursivamente
* [ ] Filtro por nombre exacto
* [ ] Filtro por wildcard (`*.c`)
* [ ] Filtro por tamaño (`+10M`, `-1K`)
* [ ] Filtro por fecha (mtime)
* [ ] Manejo de errores de permisos
* [ ] Opción de exclusión de paths

Aprendizaje clave:

* Recorrido del FS
* `stat`, tiempos, permisos

---

## 4. `ps` simplificado

* [ ] Listar `/proc`
* [ ] Detectar PIDs válidos
* [ ] Leer `/proc/[pid]/status`
* [ ] Leer `/proc/[pid]/cmdline`
* [ ] Mostrar usuario del proceso
* [ ] Mostrar estado del proceso
* [ ] Filtrar por usuario
* [ ] Ordenar por PID o memoria

Aprendizaje clave:

* Procesos
* `/proc`
* Usuarios

---

## 5. Monitor de recursos (tipo `htop` básico)

* [ ] Leer uso de CPU (`/proc/stat`)
* [ ] Leer uso de memoria (`/proc/meminfo`)
* [ ] Calcular load average
* [ ] Refrescar pantalla periódicamente
* [ ] Usar modo raw del terminal
* [ ] Mostrar lista básica de procesos

Aprendizaje clave:

* Sistema en tiempo real
* Terminal

---

## 6. Gestor de señales

* [ ] Listar procesos
* [ ] Enviar señales (`kill`)
* [ ] Manejar `SIGTERM`, `SIGKILL`
* [ ] Manejar señales personalizadas
* [ ] Detectar procesos zombie

Aprendizaje clave:

* Señales
* Control de procesos

---

## 7. Supervisor de procesos (mini systemd)

* [ ] Leer archivo de configuración
* [ ] Lanzar procesos (`fork` + `exec`)
* [ ] Reiniciar en caso de fallo
* [ ] Redirigir stdout/stderr
* [ ] Loguear eventos
* [ ] Soportar múltiples servicios

Aprendizaje clave:

* Daemons
* IPC
* Gestión de procesos

---

## 8. Watcher de filesystem

* [ ] Usar `inotify`
* [ ] Detectar create / modify / delete
* [ ] Asociar acciones a eventos
* [ ] Manejar múltiples directorios
* [ ] Evitar eventos duplicados

Aprendizaje clave:

* Eventos del FS
* Automatización

---

## 9. Auditor de permisos y seguridad

* [ ] Escanear binarios del sistema
* [ ] Detectar `setuid` / `setgid`
* [ ] Detectar permisos inseguros
* [ ] Analizar ACLs
* [ ] Generar reporte

Aprendizaje clave:

* Seguridad básica Linux
* Permisos avanzados

---

## 10. CLI de backups incrementales

* [ ] Escanear árbol de archivos
* [ ] Detectar cambios por checksum
* [ ] Crear snapshots
* [ ] Usar hardlinks para deduplicación
* [ ] Compresión (`zstd`)
* [ ] Restaurar archivos

Aprendizaje clave:

* Backups reales
* Eficiencia de storage

---

## 11. Reimplementación de `cron`

* [ ] Leer crontab
* [ ] Parsear expresiones de tiempo
* [ ] Ejecutar comandos programados
* [ ] Correr como daemon
* [ ] Loguear ejecuciones

Aprendizaje clave:

* Scheduling
* Daemons

---

## 12. Gestor de dotfiles

* [ ] Detectar archivos de configuración
* [ ] Crear symlinks en `$HOME`
* [ ] Soportar perfiles
* [ ] Seguir estándar XDG
* [ ] Sincronizar configuraciones

Aprendizaje clave:

* Entorno de usuario
* Portabilidad

---

## Orden recomendado

1. ls extendido
2. Uso de disco
3. Buscador de archivos
4. ps
5. Monitor de recursos
6. Watcher de filesystem
7. Supervisor de procesos

---

## Lenguajes sugeridos

* **C**: aprendizaje profundo del sistema
* **Rust**: herramientas modernas y seguras
* **C++**: CLIs grandes
* **Bash**: automatización y glue
