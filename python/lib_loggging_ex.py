'''
python logging library usage example
'''
import logging


# * priority levels:
# - DEBUG - lowest level
# - INFO - default level
# - WARNING - level for warning messages
# - ERROR - level for error messages
# - CRITICAL - highest level
# * for more info about logging library see: https://docs.python.org/3/library/logging.html

logging.basicConfig(level=logging.DEBUG, filename='logfile.log',
                    filemode='w', format='%(asctime)s - %(levelname)s - %(message)s')

# - prints message in logfile.log with levelname DEBUG
logging.debug('This is a debug message')
# - prints message in logfile.log with levelname INFO
logging.info('This is an info message')
# - prints message in logfile.log with levelname WARNING
logging.warning('This is a warning message')
# - prints message in logfile.log with levelname ERROR
logging.error('This is an error message')
# - prints message in logfile.log with levelname CRITICAL
logging.critical('This is a critical message')

variable = 'test'
# - prints message in logfile.log with levelname DEBUG
logging.debug('the value of variable is: %s', variable)
print('the value of variable is: %s' % variable)

try:
    1/0
except Exception as e:
    logging.exception('exception occurred: %s' % e)

# * custom loggers

logger = logging.getLogger('my_logger')  # create logger with name my_logger

# create file handler for logger
handler = logging.FileHandler(f'{logger.name}.log')

# create formatter for logger
formatter = logging.Formatter(
    '%(asctime)s - %(levelname)s - %(message)s - %(lineno)d ')

handler.setFormatter(formatter)
logger.addHandler(handler)
# prints message in logfile.log with levelname INFO
logger.info('this is an info message')

# logging.info('program ended')
