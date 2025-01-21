from enum import Enum


class ReactorResolutionMethod(Enum):
    """
    Enum describing the reactor resolution method
    """
    TRANSIENT = "Transient"
    STEADY_STATE = "Steady state"
