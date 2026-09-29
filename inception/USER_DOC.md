# User Documentation

This document explains how to use the Inception stack once it is up and running. No development knowledge required.

## What this stack provides

Three services work together to run a WordPress website:

- **NGINX** – the only service reachable from outside the machine; serves the site over HTTPS.
- **WordPress (PHP-FPM)** – runs the actual website and its admin panel.
- **MariaDB** – stores all the website's data (posts, pages, users, comments).

## Starting and stopping the project

Run these from the project root:

- `make` (or `make up`) – builds the images if needed and starts all three services in the background.
- `make down` – stops and removes the containers cleanly, without touching your data.
- `make re` – stops everything and rebuilds/restarts from scratch.

Always stop the stack with `make down`, or shut the VM down normally (`sudo reboot` / a clean shutdown). Cutting power abruptly can corrupt the database.

## Accessing the website and admin panel

- Website: `https://mgalvez-.42.fr`
- WordPress admin panel: `https://mgalvez-.42.fr/wp-admin`

This domain only resolves on this machine, because of the entry added to `/etc/hosts` — it won't work from another computer without the same entry.

## Locating and managing credentials

- Database passwords are stored as plain text files inside the `secrets/` folder at the project root (`db_password.txt`, `db_root_password.txt`). This folder is never committed to Git.
- WordPress has two users: an administrator (whose username never contains "admin" in any form, as required by the subject) and a second, non-admin user whose rights are limited to their own profile.
- WordPress user credentials can be checked or changed from the admin panel, under Users, once logged in as the administrator.

## Checking that services are running correctly

- `docker ps` – lists the three containers; all should show status `Up`.
- `docker compose logs -f <service>` – follow a specific container's logs if something looks wrong (`nginx`, `wordpress`, or `mariadb`).
- Loading `https://mgalvez-.42.fr` in a browser and seeing the actual site — not a WordPress installation screen, and not a certificate or connection error — confirms the stack is healthy.
