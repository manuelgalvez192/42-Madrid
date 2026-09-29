# Developer Documentation

## Setting up the environment from scratch

- A Linux VM with Docker Engine and the `docker compose` plugin installed.
- Clone the repository.
- Create the `secrets/` folder content by hand: `db_password.txt` and `db_root_password.txt` are intentionally excluded from Git (`.gitignore`), since they hold real passwords. Write your own values into them before building anything.
- Check `.env` at the project root: `DOMAIN_NAME` must match your own 42 login (e.g. `mgalvez-.42.fr`), and `DATA_DIR` points to where persistent data will live on the host (`/home/mgalvez-/data`).
- Add the domain to `/etc/hosts` so it resolves locally:
  ```
  127.0.0.1 mgalvez-.42.fr
  ```

## Building and launching

The whole stack is driven by the Makefile, which wraps `docker compose`:

- `make` / `make up` – builds the three images (NGINX, WordPress, MariaDB) from their own Dockerfiles and starts the containers on a custom bridge network.
- `make down` – stops and removes the containers, keeping the data volumes intact.
- `make re` – full rebuild: stops everything, then builds and starts again.
- `make clean` / `make fclean` – also remove the built images and/or the persistent data directories. Use with care, this wipes the database.

## Managing containers and volumes

- `docker ps` / `docker compose ps` – check container status.
- `docker compose logs <service>` – view logs for `nginx`, `wordpress`, or `mariadb`.
- `docker exec -it <container> sh` – open a shell inside a running container to inspect it directly.
- `docker volume ls` / `docker network ls` – inspect the volumes and the custom network the compose file creates.

## Where data lives and how it persists

All persistent data is bind-mounted from the host, under `${DATA_DIR}` (`/home/mgalvez-/data`), split into one subfolder per service that needs to keep state: the WordPress files and the MariaDB database files. Because these are bind mounts to a real path on the host filesystem — not Docker-managed volumes — the data survives `make down`, container rebuilds, and VM reboots. It is only lost if that host directory itself is deleted, or after `make fclean`.
