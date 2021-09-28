# `curl`

## How to use a REST API with bearer authentication

With the first `curl` the TOKEN is stored to a local environment variable and with the second one (by using variable substitution) it is being used to fetch data from a protected endpoint.

```bash
#!/bin/bash

TOKEN=$(curl -X 'POST' \
  'http://localhost/api/v1/login/access-token' \
  -H 'accept: application/json' \
  -H 'Content-Type: application/x-www-form-urlencoded' \
  -d 'grant_type=&username=USERNAME_HERE&password=PASSWORD_HERE&scope=&client_id=&client_secret=' \
  | jq -r '.access_token')

echo $TOKEN

curl -X 'GET' \
  'http://localhost/api/v1/gNBs/?skip=0&limit=100' \
  -H 'accept: application/json' \
  -H "Authorization: Bearer ${TOKEN}"
```
