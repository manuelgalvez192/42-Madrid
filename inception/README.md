*This project has been created as part of the 42 curriculum by mgalvez-.*

# Inception

## Description

Inception is a system administration project: the goal is to set up a small web infrastructure using Docker, instead of relying on a single all-in-one image. The stack is made of three containers, each built from its own Dockerfile and each running a single service:

- **NGINX** – the only entry point of the stack, serving the site over TLS.
- **WordPress + PHP-FPM** – runs the actual website and its admin panel.
- **MariaDB** – the database behind WordPress.

Everything runs inside one virtual machine, orchestrated with Docker Compose, and the containers only talk to each other through a private Docker network.

## Instructions

Requirements: a Linux VM with Docker Engine and the `docker compose` plugin installed.

1. Clone the repository.
2. Create `secrets/db_password.txt` and `secrets/db_root_password.txt` by hand. These files are intentionally excluded from Git (see `.gitignore`), so they don't exist right after a clone — write your own passwords into them.
3. Check `.env` at the project root: `DOMAIN_NAME` must match your 42 login (e.g. `mgalvez-.42.fr`).
4. Add that domain to `/etc/hosts` so it resolves locally:
   ```
   127.0.0.1 mgalvez-.42.fr
   ```
5. From the project root, run `make`. This builds the three images and starts the stack in the background.
6. Visit `https://mgalvez-.42.fr` in a browser.

See `DEV_DOC.md` for the full list of Makefile commands, and `USER_DOC.md` for day-to-day usage once it's running.

## Project description — Docker and design choices

Each container is built from its own Dockerfile, starting from a base image and installing only what that specific service needs — no ready-made `wordpress`, `mysql` or `nginx` images from Docker Hub, and no `latest` tags. Each container runs a single foreground process and restarts automatically if it crashes. NGINX is the only service exposing a port to the host (443, TLS only); WordPress and MariaDB are only reachable from inside the Docker network.

### Virtual Machines vs Docker

A virtual machine emulates an entire computer, including its own kernel, and needs a full OS boot per instance — heavy on disk, RAM and startup time, but with strong isolation. A Docker container shares the host's kernel and only isolates the process itself, so it starts in about a second and uses a fraction of the resources. That's why the three services here run as containers rather than as three separate VMs: each one stays isolated and reproducible without the overhead of booting three full operating systems. The whole stack still lives inside one VM at the OS level, as the subject requires; Docker only handles the isolation *between* the services.

### Secrets vs Environment Variables

A variable set in `.env` or directly in `docker-compose.yml` is readable by anyone who can run `docker inspect` on the container, and can end up in logs. A Docker secret is instead mounted as a read-only file inside the container (under `/run/secrets/`), and only the containers that declare it can see it. That's why the database passwords in this project are passed as secrets and read from files, instead of being written into `.env` as plain variables.

### Docker Network vs Host Network

With the host network, a container shares the machine's network stack directly, with no isolation. This project instead defines its own custom bridge network: the three containers reach each other only through it, by service name, and the host only sees the one port NGINX explicitly publishes. MariaDB and PHP-FPM are never reachable from outside the stack.

### Docker Volumes vs Bind Mounts

A named Docker volume is created and managed by Docker itself, stored inside Docker's own storage area. A bind mount instead maps a specific path on the host filesystem directly into a container. This project uses bind mounts, pointed at `/home/mgalvez-/data/`, because the subject requires the data to persist at that exact, predictable path on the host rather than inside Docker's internal storage.

## Resources

- Docker documentation: https://docs.docker.com/
- WordPress documentation: https://wordpress.org/documentation/
- MariaDB documentation: https://mariadb.com/kb/en/documentation/
- NGINX documentation (reverse proxy, SSL/TLS): https://nginx.org/en/docs/
- "Docker NGINX + WordPress + MariaDB Tutorial – Inception42" by alejiri (dev.to) — used as a general reference while structuring the project.

### AI usage

I used Claude (Anthropic) as a support tool during this project, specifically for:

- Understanding how NGINX's reverse proxy and TLS/SSL termination work — the part of the stack I found hardest to reason about on my own.
- Debugging Docker Compose and container startup issues, including a data-persistence problem where the database volume wasn't surviving container restarts correctly.
- Helping me organize the project's file structure and keep track of which configuration file belonged to which container.
- Drafting and structuring this documentation (`README.md`, `USER_DOC.md`, `DEV_DOC.md`), which I then reviewed and adjusted myself.

All configuration files, Dockerfiles and code in this repository were written and tested by me.
