#!/bin/sh
set -e

rm -f database-generator
f95 database-generator.f90 -o database-generator

rm -f example
f77 example.f90 -o example
