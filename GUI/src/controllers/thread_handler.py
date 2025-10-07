import multiprocessing

from PySide6.QtCore import QThread, pyqtSignal


class ThreadHandler(QThread):
    """
    Worker class that performs a background task in a separate thread.

    Signals
    -------
    finished : pyqtSignal
        Signal emitted when the background task is completed.
    """
    finished = pyqtSignal(object)
    error = pyqtSignal(str)
    stopped = pyqtSignal()

    def __init__(self):
        """
        Initializes the Worker thread and sets the running state.
        """
        super().__init__(parent=None)
        self._process = None
        self._task_function = None
        self._stop_event = multiprocessing.Event()
        self._result_queue = multiprocessing.Queue()

    def get_task_function(self) -> callable:
        """
        Get function to be called
        Returns
        -------
        task_function: callable
            Function to be called
        """

        return self._task_function

    def set_task_function(self, value) -> None:
        """
        Set function to be called
        Parameters
        ----------
        value: callable
            Function to be called

        Returns
        -------

        """
        self._task_function = value

    # Creating a property object for stask function
    task_function = property(get_task_function, set_task_function)

    def get_args(self) -> tuple:
        """
        Get function args
        Returns
        -------
        args: tuple
            Function args
        """

        return self._args

    def set_args(self, value) -> None:
        """
        Set function args
        Parameters
        ----------
        value: tuple
            Function args

        Returns
        -------

        """
        self._args = value

    # Creating a property object for stask function
    args = property(get_args, set_args)

    def run(self) -> None:
        """
        Executes a long-running task by calling external_function
        Returns
        -------

        """
        # Reset the stop event before starting a new run
        self._stop_event.clear()

        # Start the external library function as a separate process
        self._process = multiprocessing.Process(target=self._task_function,
                                                args=self._args,
                                                kwargs={'results': self._result_queue})
        self._process.start()

        # Wait for the process to complete or timeout
        self._process.join()  # Set an appropriate timeout

        # Get the result from the queue if the process completed successfully
        if not self._stop_event.is_set():
            results = self._result_queue.get() if not self._result_queue.empty() else None
        else:
            results = None

        self.finished.emit(results)

    def stop(self) -> None:
        """
        Requests the thread to stop its execution.
        Returns
        -------

        """
        if self._process:
            # Signal the process to stop
            self._stop_event.set()

            # Terminate the process forcefully if needed
            if self._process.is_alive():
                self._process.terminate()
                self._process.join()

            # Emit stopped signal after process is terminated
            if not self._process.is_alive():
                self.stopped.emit()  # Confirm process has stopped
            else:
                self.error.emit("Failed to terminate the process.")