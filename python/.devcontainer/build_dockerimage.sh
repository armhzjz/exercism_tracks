#!/bin/bash

if [ -z "$1" ]; then
    echo "provide the username as a the first and only argument"
    exit 1
else
    USERNAME=$1
fi

DOCKER_BUILDKIT=1 docker build --network host \
    --build-arg USER=$USERNAME \
    --build-arg UID=$(id -u) \
    --build-arg GID=$(id -g) \
    --secret id=token,src=$HOME/.config/exercism/user.json --tag devel-python:3.11.3 .
