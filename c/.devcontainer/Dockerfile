# syntax=docker/dockerfile:1.2
FROM    gcc:bullseye

# Create a non-root user
ARG     USER
ARG     UID
ARG     GID
ARG     USERNAME=${USER}
ARG     GROUPNAME=${USERNAME}
ARG     USER_UID=${UID}
ARG     USER_GID=${GID}
RUN     set -x && \
        groupadd \
                --gid ${USER_GID} \
                ${GROUPNAME} \
                && \
        useradd \
                --uid ${USER_UID} \
                --gid ${USER_GID} \
                --create-home \
                ${USERNAME} \
        && \
        :

RUN     set -x && \
        apt update && \
        apt upgrade -y && \
        apt install -y \
                sudo \
        && \
        echo ${USERNAME} ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/${USERNAME} && \
        chmod 0440 /etc/sudoers.d/${USERNAME} && \
        apt clean && \
        rm -fr /var/lib/apt/lists/* && \
        :
# Switch to the non-root user
USER    ${USERNAME}
# Install stuff...
RUN     set -x && \
        sudo --preserve-env apt update && \
        sudo --preserve-env apt install -y \
                cmake \
                vim \
                less \
                gdb \
                git \
                wget \
                tar \
                bsdmainutils \
                nasm \
                && \
        sudo --preserve-env apt clean && \
        sudo rm -fr /var/lib/apt/lists/* && \
        :
# Append aliases to .bashrc
RUN     set -x && \
                echo "alias l='ls'" >> ~/.bashrc
RUN     set -x && \
                echo "alias ll='ls -l'" >> ~/.bashrc
RUN     set -x && \
                echo "alias lll='ls -lA'" >> ~/.bashrc
# Install fuzzy finder
RUN     git clone --depth 1 https://github.com/junegunn/fzf.git ~/.fzf
RUN     cd ~/.fzf && ./install

# Install exercism
#  First change to bash shell to be able to echo multiline content
#  into a file
ADD --chown=$USERNAME:$USERNAME https://github.com/exercism/cli/releases/download/v3.0.13/exercism-3.0.13-linux-x86_64.tar.gz /home/$USERNAME/bin/
SHELL ["/bin/bash", "-c"]
RUN     set -x && \
        tar xf /home/$USERNAME/bin/exercism-3.0.13-linux-x86_64.tar.gz -C /home/$USERNAME/bin/ && \
        echo $'\n\
        if [ -f ~/.config/exercism/exercism_completion.bash ]; then \n\
                source ~/.config/exercism/exercism_completion.bash \n\
        fi' >> ~/.bashrc && \
        echo 'export PATH=~/bin:$PATH' >> ~/.bashrc && \
        :
# configure the exercism client with the retrieved token
RUN     --mount=type=secret,id=token,required=true export TOKEN=$(sudo cat /run/secrets/token | grep -Po '(?<=token": ").+(?=")') && \
        /home/$USERNAME/bin/exercism configure --token=$TOKEN --workspace=/workspaces
# set bash completion file for exercism
RUN     set -x && \
        mv /home/$USERNAME/bin/shell/exercism_completion.bash /home/$USERNAME/.config/exercism/exercism_completion.bash && \
        :
# remove everythin under ~/bin except the 'exercism' binary
RUN     set -x && \
        find ~/bin/ ! -name exercism ! -path ~/bin/ -delete && \
        :