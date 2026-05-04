from enum import Enum


class DatabaseType(Enum):
    """
    Enum describing the database type
    """
    NONE = "...Select database..."
    DEFAULT = "Default"
    CUSTOM = "Custom (load Cantera .yaml)"
