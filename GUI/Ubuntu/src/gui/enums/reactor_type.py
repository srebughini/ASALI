from enum import Enum


class ReactorType(Enum):
    """
    Enum describing the reactor type
    """
    TUBULAR = "Tubular"
    HONEYCOMB = "Honeycomb"
    PACKED_BED = "Packed bed"
