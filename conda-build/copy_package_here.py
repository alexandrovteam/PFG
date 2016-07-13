from conda_build.metadata import MetaData
from conda_build.build import bldpkg_path
from os.path import basename
import shutil

meta = MetaData(".")
path = bldpkg_path(meta)
shutil.copy(path, basename(path))
