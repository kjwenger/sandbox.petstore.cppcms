#!/usr/bin/env bash

BRANCH="${GIT_BRANCH}"
git checkout part/01 && \
git push && \
git checkout part/02 && \
git pull && \
git merge part/01 && \
git push && \
git checkout part/03 && \
git pull && \
git merge part/02 && \
git push && \
git checkout part/04 && \
git pull && \
git merge part/03 && \
git push && \
git checkout part/05 && \
git pull && \
git merge part/04 && \
git push && \
git checkout part/06 && \
git pull && \
git merge part/05 && \
git push && \
git checkout part/07 && \
git pull && \
git merge part/06 && \
git push && \
git checkout part/08 && \
git pull && \
git merge part/07 && \
git push && \
git checkout part/08 && \
git pull && \
git merge part/08 && \
git push && \
git checkout part/99 && \
git pull && \
git merge part/07 && \
git push && \
git checkout "${BRANCH}"