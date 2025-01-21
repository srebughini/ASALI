from enum import Enum


class ReactorGeometry(Enum):
    """
    Enum describing the heterogeneous reactor geometry
    """
    PACKED_BED = "Packed bed"
    TUBULAR = "Tubular"
    HONEYCOMB = "Honeycomb"
