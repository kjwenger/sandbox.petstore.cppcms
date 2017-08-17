#!/usr/bin/env bash

git checkout part/01 && \
git push
git checkout part/02 && \
git merge part/01 && \
git push
git checkout part/03 && \
git merge part/02 && \
git push
git checkout part/04 && \
git merge part/03 && \
git push
git checkout part/05 && \
git merge part/04 && \
git push
git checkout part/06 && \
git merge part/05 && \
git push
git checkout part/07 && \
git merge part/06 && \
git push
git checkout part/08 && \
git merge part/07 && \
git push
git checkout part/99 && \
git merge part/07 && \
git push