from enum import Enum


class ReactorGeometry(Enum):
    """
    Enum describing the heterogeneous reactor geometry
    """
    PACKED_BED = "packed_bed"
    TUBULAR = "tubular"
    HONEYCOMB = "honeycomb"
