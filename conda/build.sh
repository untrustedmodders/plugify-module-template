#!/bin/bash
# build.sh - For Linux builds

set -ex

# Create the target directories
mkdir -p $PREFIX/bin
mkdir -p $PREFIX

# Copy the shared library and module file
cp bin/libplugify-module-template.so $PREFIX/bin/
cp plugify-module-template.pmodule $PREFIX/

# Set proper permissions
chmod 755 $PREFIX/bin/libplugify-module-template.so
chmod 644 $PREFIX/plugify-module-template.pmodule

# Create activation scripts for proper library path
mkdir -p $PREFIX/etc/conda/activate.d
mkdir -p $PREFIX/etc/conda/deactivate.d

cat > $PREFIX/etc/conda/activate.d/plugify-module-template.sh << EOF
#!/bin/bash
export PLUGIFY_LM_MODULE_PATH="\${CONDA_PREFIX}:\${PLUGIFY_LM_MODULE_PATH}"
EOF

cat > $PREFIX/etc/conda/deactivate.d/plugify-module-template.sh << EOF
#!/bin/bash
export PLUGIFY_LM_MODULE_PATH="\${PLUGIFY_LM_MODULE_PATH//\${CONDA_PREFIX}:/}"
EOF

chmod +x $PREFIX/etc/conda/activate.d/plugify-module-template.sh
chmod +x $PREFIX/etc/conda/deactivate.d/plugify-module-template.sh