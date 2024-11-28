from enum import Enum


class ReactorResolutionMethod(Enum):
    """
    Enum describing the reactor resolution method
    """
    TRANSIENT = "transient"
    STEADY_STATE = "steady_state"
