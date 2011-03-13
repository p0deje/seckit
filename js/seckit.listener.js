/**
 * Implements behaviors.
 *
 * @param context
 */
Drupal.behaviors.seckit = function(context) {
  seckit_listener_hsts($('#edit-seckit-ssl-hsts', context));
  seckit_listener_csp($('#edit-seckit-xss-csp-checkbox', context));
  seckit_listener_origin($('#edit-seckit-csrf-origin', context));
  $('#edit-seckit-ssl-hsts', context).click(function() {
    seckit_listener_hsts(this)
  });
  $('#edit-seckit-xss-csp-checkbox', context).click(function() {
    seckit_listener_csp(this)
  });
  $('#edit-seckit-csrf-origin', context).click(function() {
    seckit_listener_origin(this)
  });
}

/**
 * Gets checkbox status and executes necessary functions
 * to HTTP Strict Transport Security fieldset.
 *
 * @param element
 */
function seckit_listener_hsts(element) {
  if ($(element).is(':checked')) {
    seckit_listener_enable_hsts(element);
  }
  else {
    seckit_listener_disable_hsts(element);
  }
}

/**
 * Gets checkbox status and executes necessary functions
 * to Content Security Policy fieldset.
 *
 * @param element
 */
function seckit_listener_csp(element) {
  if ($(element).is(':checked')) {
    seckit_listener_enable_csp(element);
  }
  else {
    seckit_listener_disable_csp(element);
  }
}

/**
 * Gets checkbox status and executes necessary functions
 * to Origin fieldset.
 *
 * @param element
 */
function seckit_listener_origin(element) {
  if ($(element).is(':checked')) {
    seckit_listener_enable_origin(element);
  }
  else {
    seckit_listener_disable_origin(element);
  }
}

/**
 * Enables Content Security Policy form elements.
 *
 * @param element
 */
function seckit_listener_enable_csp(element) {
  $('#edit-seckit-xss-csp-allow').removeAttr('disabled');
  $('#edit-seckit-xss-csp-options').removeAttr('disabled');
  $('#edit-seckit-xss-csp-img-src').removeAttr('disabled');
  $('#edit-seckit-xss-csp-media-src').removeAttr('disabled');
  $('#edit-seckit-xss-csp-script-src').removeAttr('disabled');
  $('#edit-seckit-xss-csp-object-src').removeAttr('disabled');
  $('#edit-seckit-xss-csp-frame-src').removeAttr('disabled');
  $('#edit-seckit-xss-csp-font-src').removeAttr('disabled');
  $('#edit-seckit-xss-csp-xhr-src').removeAttr('disabled');
  $('#edit-seckit-xss-csp-style-src').removeAttr('disabled');
  $('#edit-seckit-xss-csp-frame-ancestors').removeAttr('disabled');
  $('label[for="edit-seckit-xss-csp-allow"]').append('<span title="' + Drupal.t('This field is required.') + '" class="form-required">*</span>');
}

/**
 * Disables Content Security Policy form elements.
 *
 * @param element
 */
function seckit_listener_disable_csp(element) {
  $('#edit-seckit-xss-csp-allow').attr('disabled', 'disabled');
  $('#edit-seckit-xss-csp-options').attr('disabled', 'disabled');
  $('#edit-seckit-xss-csp-img-src').attr('disabled', 'disabled');
  $('#edit-seckit-xss-csp-media-src').attr('disabled', 'disabled');
  $('#edit-seckit-xss-csp-script-src').attr('disabled', 'disabled');
  $('#edit-seckit-xss-csp-object-src').attr('disabled', 'disabled');
  $('#edit-seckit-xss-csp-frame-src').attr('disabled', 'disabled');
  $('#edit-seckit-xss-csp-font-src').attr('disabled', 'disabled');
  $('#edit-seckit-xss-csp-xhr-src').attr('disabled', 'disabled');
  $('#edit-seckit-xss-csp-style-src').attr('disabled', 'disabled');
  $('#edit-seckit-xss-csp-frame-ancestors').attr('disabled', 'disabled');
  $('span[title="' + Drupal.t('This field is required.') + '"]').remove();
}

/**
 * Enables Origin form elements.
 *
 * @param element
 */
function seckit_listener_enable_origin(element) {
  $('#edit-seckit-csrf-origin-whitelist').removeAttr('disabled');
}

/**
 * Disables Origin form elements.
 *
 * @param element
 */
function seckit_listener_disable_origin(element) {
  $('#edit-seckit-csrf-origin-whitelist').attr('disabled', 'disabled');
}

/**
 * Enables HTTP Strict Transport Security form elements.
 *
 * @param element
 */
function seckit_listener_enable_hsts(element) {
  $('#edit-seckit-ssl-hsts-max-age').removeAttr('disabled');
  $('#edit-seckit-ssl-hsts-subdomains').removeAttr('disabled');
}

/**
 * Disables HTTP Strict Transport Security form elements.
 *
 * @param element
 */
function seckit_listener_disable_hsts(element) {
  $('#edit-seckit-ssl-hsts-max-age').attr('disabled', 'disabled');
  $('#edit-seckit-ssl-hsts-subdomains').attr('disabled', 'disabled');
}